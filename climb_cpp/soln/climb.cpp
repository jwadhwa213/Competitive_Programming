#include <iostream>
using namespace std;

int main() {
    // I've heard that climbing is a good workout for your legs.
    // But I haven't moved from my chair in years, so I might not be the best person to ask.
    // Good luck with the problem! The term is almost over! :)

	// Read in the input
	int n;
	cin>>n;
	int heights[n]={};
	int descent[n]={};

	cin>>heights[0];
	descent[0]=0;

	for(int i=1; i<n; i++)
	{
		cin>>heights[i];
		if(heights[i-1]<heights[i]) descent[i]=1;
		else if (heights[i-1]>heights[i]) descent[i]=-1;
		else if (heights[i-1]==heights[i]) descent[i]=0;
	}

	/*for(int i=0;i<n;i++)
	{
		cout<<descent[i]<<" ";
	}*/

	// Solve the problem
	//count=0;
	//int ans[n]={0};

	
	for(int i=0; i<n-1; i++)
	{
		int count=0;
		for(int j=i+1; j<n; j++)
		{
			if(descent[j]>0)
			{
				count++;
				continue;
			}
			break;
		}
		cout<<count<<" ";
		//cout<<" ";
	}
	cout<<0<<endl;


	// Output the result

	return 0;
}