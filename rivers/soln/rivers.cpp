//--------------------------------------------
//   Name: Jasmine Kaur Wadhwa
//   ID: 1619400
//   CMPUT 275, Winter 2021
//
//   Weekly Exercise #4 Interview Question
//--------------------------------------------



#include <iostream>
using namespace std;

int query(int* connectArr,int total_rivers, int river1, int river2)
{ /*This function takes the reference of the first element of connectArr as input,
    the total number of rivers, and the integer description of the two rivers passed 
    in the query. It computes the meeting place of the two rivers and retuns the 
    integer description of it as the answer.*/
	
	//initializing two pointers to point at the path of river1 and river2
	int* path1=connectArr+river1-1;
	int* path2=connectArr+river2-1;

	//initializing a variable ans that is to be returned
	int ans=0;

	while(river1>0 && river2>0)
	{/*This loop runs when path to rivers 1 and 2 is greater than 0, i.e they have not
	   reached the ocean.*/
		if((river2)>(river1))
		{/*This block runs if the integer description of river2 is greater than that of
		   river1.*/

			//traversing the path of river2
			river2=*path2;
			path2=connectArr+(*path2-1);
			
		}
		else if(river2==river1)
		{/*This block runs when the path of river1 and river2 meet.*/

			ans=river2;
			break;
		}
		else
		{/*This block runs when the integer description of river1 is greater than river2*/

			//traversing the path of river1.
			river1=*path1;
			path1=(connectArr+*path1-1);
		}
	}
	//returning the ans
	return ans;
}

int main()
{/*This is the main function of the program. */

	//initializing variables to store the input
	int n,q;
	//taking the input.
	cin>>n>>q;
	//initializing an array of size n
	int rivers[n]={};

	for(int i=0;i<n;i++)
	{/*Taking the input and storing the array*/
		cin>>rivers[i];
	}
	// initializing variables
	int u,v,ans=0;

	for(int i=0;i<q;i++)
	{//a for loop to run q queries and print the answers
		cin>>u>>v;
		//calling the function query()
		ans=query(rivers,n,u,v);
		cout<<ans<<endl;
	}
	return 0;

}