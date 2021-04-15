// Remember style matters!
#include <iostream>
#include <string.h>
#include <map>
#include <bits/stdc++.h>
using namespace std;

string build_path(string str1,string str2,string path)
{
	if(str2=="..")
	{
		//find last occurence of "/" and remove word ahead of it from path
		int pos=path.find_last_of("/");
		string sub= path.substr(0,pos);
		//cout<<"path:"<<sub<<endl;
		if(path == "")
		{
			path="/";
			//cout<<"path is empty"<<endl;
		}
		else
		{
			path=sub;	
		}
		
	}
	else
	{
		if(path=="/")
		{
			path=path+str2;
		}
		else
		{
			path=path+"/"+str2;
		}
	}
	return path;
}
void print_files(map<string,set<string> > history)
{
	map<string, set<string>>::iterator itr;
	for(itr=history.begin();itr!=history.end();++itr)
	{
		cout<<itr->first;
		set<string>::iterator itr2;
		itr2=(itr->second).begin();
		while(itr2!=(itr->second).end())
		{
			cout<<" ";
			cout<<*itr2;
			++itr2;
		}
		cout<<endl;
	}
}

int main()
{
	int num=0;
	cin>>num;
	string str1="",str2="",path="/";
	//declaring a map named history
	map<string,set<string> > history;
	set<string> values;

	history[path]=values;
	
	for(int i=0;i<num;i++)
	{
		cin>>str1>>str2;

		if(str1=="ls")
		{
			//cout<<str2<<endl;
			//if(path == "")
			//{
			//	path="/";
			//}

			history[path].insert(str2);
			//cout<<str2<<endl;
		}
		if(str1=="cd")
		{
			path=build_path(str1,str2,path);
			if(history.find(path)==history.end())
			{
				history[path]=values;	
			}	
				
		}
		
	}
	print_files(history);
	return 0;
}

