//--------------------------------------------
//   Name: Jasmine Kaur Wadhwa
//   ID: 1619400
//   CMPUT 275, Winter 2021
//
//   Weekly Exercise #3 Interview Question
//--------------------------------------------


#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	/*This is the main funcion of the program.*/

	//Initializing variables
	int n=0,T=0;
	string str="NO";

	//Taking input for n and T, where n is the number of products and T is the 
	//amount to look for
	cin>>n>>T;
	//initializing an empty array of size n to store the prices of the the products
	int arr[n]={};
	for(int i=0;i<n;i++)
	{
		//a for loop to input price of n items
		cin>>arr[i];
	}

	//initializing variables
	int start=0,end=n-1;
	double mid=0.0;
	int mid_ind=0;

	while(start!=end)
	{	//This while loop runs when start!=end

		//compute the middle index of the array according to the values of start 
		//and end
		mid=ceil((start+end)/2);
		//converting to int
		mid_ind=int(mid);

		//updating the value of end if value in arr at index mid is equal to or 
		//greater than T
		if(arr[mid_ind]>=T)	end=mid_ind-1;
		
		//else update value of start if value in arr at index mid is less than T.
		else start=mid_ind+1;
	}
	//make start=0
	start=0;
	//initializing sum
	int sum=0;

	while(start!=end)
	{	//This while loop runs when start!=end
		//compute sum 
		sum=arr[start]+arr[end];
		if(sum==T)
		{	//update str="YES" if sum==T
			str="YES";
			start=end;
		}
		else if(sum<T)
		{	//update start if sum is less than T
			//increase the start index by 1   
			start+=1;
		}
		else
		{	//update end if sum is greater than T.
			//decrease the end index by 1.
			end-=1;
		}
	}
	//print the result
	cout<<str<<endl;
	return 0;
}
