#include <iostream>

using namespace std;

int main() {
  // Good luck! The term is almost over!
	int n;
	cin>>n;
	int floors[n]={};
	int climb[n]={};

	cin>>floors[0];
	climb[0]=0;

	for(int i=1; i<n; i++)
	{
		cin>>floors[i];
		climb[i]=floors[i]-floors[i-1];
	}

	int up=0;

	for(int i=1; i<n; i++)
	{
		if(climb[i]>0)
		{
			up+=climb[i];
		}
	}
	cout<<up<<endl;


  
  return 0;
}