#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
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

};*/

/*

void Digraph::addVertex(string v) {
  // If it already exists, does nothing.
  // Otherwise, adds v with an empty adjacency set.
  nbrs[v];
}

void Digraph::addEdge(string v, string u) {
  //addVertex(v);
  nbrs[v].push_back(u); // will also add u to nbrs if it was not there already
}*/


bool isVertex(const unordered_map<string, vector<string>>& nbrs,string v) {
  return nbrs.find(v) != nbrs.end();
}

vector<string>::const_iterator neighbours(unordered_map<string, vector<string>>& nbrs, string v){
  // this will crash the program if v is not a vertex
  return (nbrs.find(v)->second).begin();
}

vector<string>::const_iterator endIterator(unordered_map<string, vector<string>>& nbrs, string v) {
  // this will crash the program if v is not a vertex
  return (nbrs.find(v)->second).end();
}


int max_depth(unordered_map<string, vector<string>>& nbrs, string target, unordered_map<string,int>& num_dependencies) {
	/*This method takes the reference of an instance of the graph class, a vertex v
	   a reference of the vector searchTree. It recursively calls itself
	  for all the vertices not seen before and adds them to the searchTree. */

  int longest=0,len=0;
  //counter[v];
  if (num_dependencies.find( target) == num_dependencies.end()) 
  {
  	//cout<<"check1 "<<target<<endl;

  	if(!isVertex(nbrs,target))
  	{
  		//cout<<"basecase "<<target<<endl;
  		return 0;
  	}
  	for (auto iter = neighbours(nbrs,target); iter != endIterator(nbrs,target); iter++) {
  		//cout<<"check2 : neighbour "<< *iter<<endl;
  		len=1+max_depth(nbrs,*iter, num_dependencies);
  	
  		if(len > longest) longest=len;
  	}

  		num_dependencies[target]=longest;
  		//cout<<"check4 "<<target<<endl;
  		return num_dependencies[target];
 
  }
  else{
  	//cout<<"check3 "<<target<<endl;
  	return num_dependencies[target];
  }
}

int main()
{
	/*The main function declares an instance of the Digraoh class defined above and uses it to
	 create a graph to store the makefile targets and its dependencies. It then reads the make 
	 commands from stdin, calls the function depthFirstSearch() to build the files and prints 
	 the results to stdout.*/


	// an instance of class Digraph
	//Digraph graph;
	// taking input
	int n;
	cin>>n;

	//cout<<"num read: "<<n<<endl;
	unordered_map<string,int> num_dependencies;

	unordered_map<string, vector<string>> nbrs;
	

	for (int i=0;i<n;i++)
	{/*Building the graph, adding the targets as vertex and the dependencies as its 
		neighbours.*/
		int k;
		string str1;
		// the variable k represents the number of dependencies the target has
		cin>>k;
		// input the target name
		cin>>str1;
		//cout<<"string read: "<<str1<<endl;
		// add the target to the graph
		int pos=str1.find(":");
		str1=str1.substr(0,pos);
		//graph.addVertex(str1);
		nbrs[str1];
		
		for(int j=0;j<k;j++)
		{//take the dependencies as input
			string str2="";
			cin>>str2;
			//add the dependencies as the neighbours of the directed graph
			//graph.addEdge(str1, str2);
			nbrs[str1].push_back(str2);
		}
	
	}

	int len_max=0;
	unordered_map<string, vector<string>>::iterator it=nbrs.begin();
	for( ; it != nbrs.end() ; ++it)
	{
		//cout<<it->first<<" ";
		
		len_max=max_depth(nbrs,it->first, num_dependencies);
		//cout<< len<<endl;
	}

	

	unordered_map<string, int>::iterator it1=num_dependencies.begin();
	for( ; it1 != num_dependencies.end() ; ++it1)
	{
		//cout<<it->first<<" ";
		if(it1->second>len_max) 
			len_max=it1->second;
	
	}
	cout<<len_max<<endl;


	return 0;
}// Remember, style matters!
