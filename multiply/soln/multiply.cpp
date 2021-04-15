#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[100], b[100]; 
  int n, m;
  cin>>n>>m;
  // Read the input
  for(int i=0;i<n;i++)
  {
  	cin>>a[i];
  }
  for(int i=0;i<m;i++)
  {
  	cin>>b[i];
  }

  vector<int> result(m+n,0);

  int i_n1=0;
  int i_n2=0;

  for(int i=n-1;i>=0;i--)
  {
  	int carry=0;
  	int n1=a[i];

  	i_n2=0;

  	for(int j=m-1;j>=0;j--)
  	{
  		int n2=b[j];

  		int sum=n1*n2+ result[i_n1+i_n2]+carry;
  		carry=sum/10;
  		result[i_n1+i_n2]=sum%10;
  		i_n2++;
  	}

  	if (carry>0)
  		result[i_n1+i_n2]+=carry;
  	//cout<<result[i+n1+i_n2]<<endl;

  	i_n1++;
  }

 
  cout<<result[m+n-1];
  for(auto i=(m+n-2);i>=0;i--)
  {
  	cout<<" ";
	cout<<result[i];
  }
  cout<<endl;


  return 0;

}
