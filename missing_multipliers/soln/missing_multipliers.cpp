#include <iostream>
using namespace std;


int main(){
	int n,m;

	cin>>n>>m;

	long long int numbers[n]={0};
	long long int cummBegin[n]={0};
	long long int cummEnd[n]={0};
	long long int result[n]={0};

	cin>>numbers[0];
	cummBegin[0]=numbers[0];

	for(int i=1; i<n; i++)
	{
		cin>>numbers[i];
		cummBegin[i]=cummBegin[i-1]*numbers[i];
	}
	cummEnd[n-1]=numbers[n-1];
	for(int i=n-2; i>=0 ; i--)
	{
		cummEnd[i]=cummEnd[i+1]*numbers[i];
	}

	for(int i=0; i<n ; i++)
	{
		if((i-m)<=0 && (i+m)>=(n-1))
		{
			result[i]=0;
		}
		else
		{
			if(i-m<=0)
			{
				result[i]=cummEnd[i+m+1];
			}
			else if(i+m>=n-1)
			{
				result[i]=cummBegin[i-m-1];
			}
			else
			{
				result[i]=cummBegin[i-m-1]*cummEnd[i+m+1];
			}

		}
	}

	cout<<result[0];
	for(int i=1; i<n; i++)
	{
		cout<<" ";
		cout<<result[i];
	}
	cout<<endl;

	return 0;
}