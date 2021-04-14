#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Digraph {
public:
	
	unordered_map<string, string> searchTree ;

  // add a vertex, does nothing if it already exists
  void addVertex(string v);

  // adds an edge, creating the vertices if they do not exist
  // if the edge already existed, does nothing
  void addEdge(string u, string v);

  // returns true if and only if v is a vertex in the graph
  bool isVertex(string v);

  // returns a const iterator to the neighbours of v
  vector<string>::const_iterator neighbours(string v) const;

  // returns a const iterator to the end of v's neighour set
  vector<string>::const_iterator endIterator(string v) const;

  private:
  	//private attributes of the class
  unordered_map<string, vector<string>> nbrs;

};

void depthFirstSearch(Digraph& graph, string v, string parent, 
	vector<string>& searchTree) {
	/*This method takes the reference of an instance of the graph class, a vertex v
	  its parent p and a reference of the vector searchTree. It recursively calls itself
	  for all the vertices not seen before and adds them to the searchTree. */
	
  if (graph.searchTree.find(v) != graph.searchTree.end()) {
    return; // already visited this node or is not a target
  }

  // if not already visited, add to the searchTree of the graph class
  graph.searchTree[v]=parent;

  for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
  	//iterating through the neighbours of vertex v

  	//if iter points at a vertex, recursively call depthFirstSearch
  	if(graph.isVertex(*iter)) depthFirstSearch(graph, *iter, v, searchTree);
  }
  //add to the vector searchTree, once target is made
  searchTree.push_back(v);
}

void Digraph::addVertex(string v) {
  // If it already exists, does nothing.
  // Otherwise, adds v with an empty adjacency set.
  nbrs[v];
}

void Digraph::addEdge(string v, string u) {
  //addVertex(v);
  nbrs[v].push_back(u); // will also add u to nbrs if it was not there already
}


bool Digraph::isVertex(string v) {
  return nbrs.find(v) != nbrs.end();
}

vector<string>::const_iterator Digraph::neighbours(string v) const {
  // this will crash the program if v is not a vertex
  return (nbrs.find(v)->second).begin();
}

vector<string>::const_iterator Digraph::endIterator(string v) const {
  // this will crash the program if v is not a vertex
  return (nbrs.find(v)->second).end();
}

int main()
{
	/*The main function declares an instance of the Digraoh class defined above and uses it to
	 create a graph to store the makefile targets and its dependencies. It then reads the make 
	 commands from stdin, calls the function depthFirstSearch() to build the files and prints 
	 the results to stdout.*/


	// an instance of class Digraph
	Digraph graph;
	// taking input
	int n,m;
	cin>>n>>m;
	

	for (int i=0;i<n;i++)
	{/*Building the graph, adding the targets as vertex and the dependencies as its 
		neighbours.*/
		int k;
		string str1;
		// the variable k represents the number of dependencies the target has
		cin>>k;
		// input the target name
		cin>>str1;
		// add the target to the graph
		int pos=str1.find(":");
		str1=str1.substr(0,pos);
		graph.addVertex(str1);
		
		for(int j=0;j<k;j++)
		{//take the dependencies as input
			string str2="";
			cin>>str2;
			//add the dependencies as the neighbours of the directed graph
			graph.addEdge(str1, str2);
		}
		
	}

	for(int i=0;i<m;i++)
	{// read m commands one by one from the command line
		string command,startVertex;
		cin>>command>>startVertex;
		

		if(graph.searchTree.find(startVertex)!=graph.searchTree.end())
		{ // if the target has already been built
			cout<<"make: "<<"`"<<startVertex<<"' "<< "is up to date."<<endl;	
		}
		else
		{ //if the target has not been built

			//call depthFirstSearch for the target that has not been built already
			//and update the result in the vector searchTree
			vector<string> searchTree;
			string parent="-1";
			depthFirstSearch(graph, startVertex, parent, searchTree);


			//print the files in the order that they were built
			auto it=searchTree.begin();
			cout<<*it;
			it++;
			while(it!=searchTree.end())
			{
				cout<<" ";
				cout<<*it;
				it++;
			}
			cout<<endl;
		}
	}
	return 0;
}