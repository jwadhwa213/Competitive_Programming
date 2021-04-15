#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	
	string s="";
	int size;
	cin>>size;
	cin>>s;

	int counter[26]={};
	int pairs=0,output=0;

	for(int i=0;i<26;i++){
		counter[i]=count(s.begin(),s.end(),char(97+i));
		pairs+=counter[i]/2;
	}

	if(size>(pairs*2))
	{
		output=pairs*2+1;
		//cout<<output<<endl;
	}
	if(size==(pairs*2))
	{
		output=pairs*2;
		
	}
	cout<<output<<endl;

	//cout<<s<<endl;
	
	return 0;
}
