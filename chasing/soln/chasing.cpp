#include <iostream>

using namespace std;

int main() {
  // declare variables
	int S,A;

  // read the input
	cin>>S>>A;
	int arr[A]={};
	for(int i=0;i<A;i++)
	{
		cin>>arr[i];
	}
  // solve the problem
	int j=0,count=0;
	while(arr[j]>=0)
	{
		count+=1;
		if(count>A)
		{
			cout<<"There was a cycle"<<endl;
			j=-1;
			break;
		}
		j=arr[j]-S;
	}
	if(j>=0) cout<<arr[j]<<endl;
  // print the output

  return 0;
}
