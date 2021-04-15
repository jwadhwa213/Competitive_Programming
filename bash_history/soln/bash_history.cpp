#include <iostream>
#include <string.h>
#include <map>
#include <bits/stdc++.h>
using namespace std;


void print_files(map<string,set<string> > history)
{	/* This functtion takes a copy of the map and prints the directory names and
	   the names of the files contained in them*/

	// instantiates an iterator of type map
	map<string, set<string>>::iterator itr;
	for(itr=history.begin();itr!=history.end();++itr)
	{// a loop to run through all the keys in the map history
		
		//print the key pointed to by itr
		cout<<itr->first;
		//an iterator of type set to run through each element in the set
		set<string>::iterator itr2;
		//itr2 now points to the beginning of the set that is pointed to by itr
		itr2=(itr->second).begin();
		while(itr2!=(itr->second).end())
		{/*this while loop prints all the elements in the set*/
			cout<<" ";
			cout<<*itr2;
			++itr2;
		}
		cout<<endl;
	}
}

int main()
{/* This is the main method of the program */
	
	//initializing variables
	int num=0;
	//taking in the number that denotes the number of lines to be read
	cin>>num;
	//initializing path to represent the root directory
	string str1="",str2="",path="/";
	
	//declaring a map named history and an empty set named values
	map<string,set<string> > history;
	set<string> values;

	//creating a key of the root directory
	history[path]=values;
	
	for(int i=0;i<num;i++)
	{/*A loop to take num inputs*/

		// storing the two strings as str1 and str2
		cin>>str1>>str2;

		if(str1=="ls")
		{//if the command is 'ls'

			if(path == "")
			{ // if the path is empty assign it to "/" to represent the root directory
				path="/";
			}
			//add the filename stored in str2 to the map, history, paired with the key
			//of the current directory
			history[path].insert(str2);
		}

		if(str1=="cd")
		{//If the command is "cd".
			if(str2=="..")
			{// if the command is ".." i.e to exit the directory.

				//find last occurence of "/" and remove word ahead of it from path
				int pos=path.find_last_of("/");
				string sub= path.substr(0,pos);
				
				if(path == "")
				{// if the path is empty, assign it as "/" to represent the root 
				 // directory
					path="/";
				}
				else
				{// otherwise stored the sub string in path
					path=sub;	
				}
				
			}
			else
			{ // if the command is to enter a directory, append the name of the directory 
			  // to the path
				if(path=="/")
				{//append to the root directory
					path=path+str2;
				}
				else
				{//append to the current path
					path=path+"/"+str2;
				}

				if(history.find(path)==history.end())
				{//add the key to the map if it doesn't already exist
					history[path]=values;	
				}	
			}
				
		}
		
	}

	//print all the files
	print_files(history);
	return 0;
}

