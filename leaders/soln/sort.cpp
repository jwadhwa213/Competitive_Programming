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
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
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
	//int leaders;
	int sorted_arr[n];
	
	for(int i=0; i<n;i++)
	{
		sorted_arr[i]=arr[i];
	}

	quickSort(sorted_arr,0,n-1);

	/*for(int i=0;i<n;i++)
	{
		cout<<sorted_arr[i]<<" ";
	}*/
	int index;
	//int l=sizeof(indices)/sizeof(indices[0]);
	//cout<<l<<endl;
	int cnt=0;
	int elem=sorted_arr[n-1];    //stores the last element of the sorted array
	//cout<<elem<<endl;
	for(int i=0;i<n;i++)		//n= size of arr[]
	{
		if(arr[i]==elem)
		{
			//cout<<count<<endl;
			cnt+=1;
			index=i;
			//cnt_elem+=1;
			//cout<<indices[count]<<endl;
		}
	}
	//delete[] indices;

	
	//int l=sizeof(indices)/sizeof(indices[0]);
	//cout<<elem<<" "<<l<<endl;
	//cout<<elem<<" "<<l<<endl;
	//cout<<l<<endl;
	/*for(int i=0;i<l;i++)
	{
		cout<<indices[i]<<" ";
	}*/
	reverse(arr,arr+index);
	//int cnt_lead=0;
	int leaders=index;
	cout<<arr[leaders];
	//int ind=0;
	//int length;
	

	for(int i=n-cnt-1;i>=0;i-=cnt)
	{
		
		//int *index= new int[n];
		//length=sizeof(index)/sizeof(index[0]);
		//cout<<length<<endl;

		//cnt_elem=0;
		elem=sorted_arr[i];
		//cout<<i<<" "<<elem<<endl;
		cnt=0;
		//cout<<i<<" "<<elem<<endl;
		for(int j=0;j<n;j++)
		{
			if(arr[j]==elem)
			{
				cnt+=1;
				index=j;
				
				//cout<<j<<" "<<indices[cnt_elem]<<endl;
				//cnt_elem+=1;
			}

		}
		//cout<<index<<" "<<cnt<<endl;
		//int len=sizeof(index)/sizeof(index[0]);
		//cout<<len<<endl;
		//cout<<elem<<" "<<l<<endl;
		/*for(int i=0;i<len;i++)
		{
			cout<<index[i]<<" ";
		}*/
		//cout<<endl;
		
		if(leaders<index)
		{
			cout<<arr[leaders]<<" ";
			int begin=leaders+1;
			int end=index;
			reverse(arr+begin,arr+end);
			//cnt_lead+=1;
			leaders=index;
			/*for(int i=0;i<n;i++)
			{
				cout<<arr[i]<<" ";
			}*/
		}
		
		
		/*for(int i=0;i<len;i++)
		{
			cout<<index[i]<<" ";
		}
		delete[] index;*/
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}