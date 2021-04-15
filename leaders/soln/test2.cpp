#include <iostream> // this is the only header you may use (for cin, cout, and endl)
using namespace std;

void reverse(int *begin,int *end)
{
	int temp=0;
	end-=1;
	while(begin<end)
	{
		temp=*begin;
		*begin=*end;
		*end=temp;

		begin+=1;
		end-=1;
	}

}
int main()
{
	//int arr[]={8,2,1,7,8,7,2,1,7};
	//int n=sizeof(arr)/sizeof(arr[0]);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];

	}

	int max=arr[0];
	int leader=0;

	for(int i=leader+1;i<n;i++)
	{
		if(arr[i]>=max)
		{
			max=arr[i];
			leader=i;
		}
	}
	reverse(arr,arr+leader);
	cout<<arr[leader];

	int index;



	while(leader<(n-1))
	{
		max=arr[leader+1];
		for(int i=leader+1;i<n;i++)
		{
			if(arr[i]>=max)
			{
				max=arr[i];
				index=i;
			}
		}
		
		cout<<" ";
			
		int begin=leader+1;
		int end=index;
		reverse(arr+begin,arr+end);
		leader=index;
		cout<<arr[leader];
	}

	cout<<endl;
	for(int i=0;i<n-1;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<arr[n-1]<<endl;
	return 0;
}