#include <iostream>
#include <cmath>
using namespace std;

int main(){
	// Declare your variables
	int n;
	double t;
	cin>>n>>t;
	int s,e,hours,blocked;
	int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};

	for(int i=0;i<n;i++)
	{
		cin>>s>>e;
		hours= (s<e)?e-s:s-e;
		blocked=24-hours;

		while(blocked>0)
		{
			if(e==23)
			{
				arr[e]=-1;
				blocked-=1;
				e=0;
			}
			else
			{
				arr[e]=-1;
				blocked-=1;
				e+=1;
			}
		}
	}
	double count=0;
	for(int i=0;i<24;i++)
	{
		//cout<<arr[i]<<" ";
		if(arr[i]!=-1)
		{

			count+=1;
			
		}
	}
	//cout<<endl;
	//cout<<count<<endl;
	if(count==0)
	{
		cout<<"IMPOSSIBLE"<<endl;

	}
	else
	{
		double days=t/count;
		//cout<<t<<" "<<days<<endl;
		double ans=ceil(days);
		cout<<ans<<endl;
	}

	






	// Read the input

	// Solve the problem. Good luck! :)

	// Output the answer

	
	return 0;
}