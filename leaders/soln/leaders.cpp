//--------------------------------------------
//   Name: Jasmine Kaur Wadhwa
//   ID: 1619400
//   CMPUT 275, Winter 2021
//
//   Weekly Exercise #2
//--------------------------------------------


#include <iostream> // this is the only header you may use (for cin, cout, and endl)
using namespace std;

void reverse(int *begin,int *end)
{
	/*This function performs array reversal. It takes the two pointers that are pointing into an 
	array and reverses all entries between these pointers including the array pointed to by begin
	but not the entry pointed to by end.*/
	
	int temp=0; 		//initializing a temporary storage variable
	end-=1;				//decrementing end by 1

	while(begin<end)
	{
		//this while loop terminates when begin==end or begin>end
		//the following lines swap the value at index begin and index end in the array being pointed to
		temp=*begin;
		*begin=*end;
		*end=temp;

		//incrementing begin and decrementing end
		begin+=1;
		end-=1;
	}

}
int main()
{
	/*This is the main funcion of the program.*/

	//Taking input n and the array.
	int n;				//n stores the length of the array passed.
	cin>>n;				
	int arr[n];			//arr stores the array of size n that is being passed
	int index;			//inilizing an empty variable store leader index
	for(int i=0;i<n;i++)
	{
		//this for loop takes the input of the elements of the array and stores them in arr[]
		cin>>arr[i];

	}

	int max=arr[0];		//initializing the first index of arr as max.
	int leader=0;		//initializing 0 to leader

	for(int i=leader+1;i<n;i++)
	{
		//this for loop runs through the entire array to find the first leader
		if(arr[i]>=max)
		{
			//this conditional if block executes only when the element at index i is greater 
			//than max, replaces the value of max with arr[i] and value of leaders index i 
			max=arr[i];
			leader=i;
		}
	}

	//reversing the array
	reverse(arr,arr+leader);
	//printing the leader
	cout<<arr[leader];

	while(leader<(n-1))
	{
		//This while loop exits until the leader=n (last index of the array)
		//initializing the max variable 
		max=arr[leader+1];

		for(int i=leader+1;i<n;i++)
		{
			//checking for leaders
			if(arr[i]>=max)
			{
				max=arr[i];
				index=i;
			}
		}
		
		cout<<" ";
		
		//reversing the array between the previous leader and the next leader
		int begin=leader+1;			//initializing the beginning index 
		int end=index;				//initializing the ending index
		reverse(arr+begin,arr+end); //calling the reverse function
		leader=index;				//replacing the old leader index with the new leader index
		cout<<arr[leader];			//printing the 
	}

	cout<<endl;

	for(int i=0;i<n-1;i++)
	{
		//printing the reversed array
		cout<<arr[i]<<" ";
	}
	cout<<arr[n-1]<<endl;
	return 0;
}