#include <iostream>
using namespace std;

int main() {

    // Read in the input
    int n,q;
    cin>>n>>q;
    int calls[n]={};
    int cumulative[n]={};
    
    cin>>calls[0];
    cumulative[0]=calls[0];

    for(int i=1;i<n;i++)
    {
    	cin>>calls[i];
    	cumulative[i]+=cumulative[i-1]+calls[i];
    }

    // Solve the problem
    int s,t;
    while(q>0)
    {
    	int eliminate=0,ans=0;
    	cin>>s>>t;
    	if(s==1)
    	{
    		eliminate=0;
    	}
    	else
    	{
    		eliminate=cumulative[s-2];
    	}

    	ans=cumulative[t-1]-eliminate;
    	cout<<ans<<endl;
    	q-=1;
    }

    // Output the result

    return 0;
}