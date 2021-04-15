#include <iostream>
# include <queue>
using namespace std;

int main() {
	// Read in the input
	int n,m;
	cin>>n>>m;

	queue<int> west,east;

	for(int i=0;i<n;i++)
	{
		int num=0;
		cin>>num;
		west.push(num);
	}
	for(int i=0;i<m;i++)
	{
		int num=0;
		cin>>num;
		east.push(num);
	}

	// Solve the problem
	int w=0,e=0;
	// bank=0 for west and bank=1 for east
	int bank=0;

	//ferry starts at the west bank and travels to the east bank
	int time=0;
	
	while(w<n || e<m)
	{
		int arrival=0,waiting=0;
		if(w==n)
		{ //operate on east
			arrival=east.front();
			
			waiting=arrival-time;
			if(waiting>0) time+=waiting;
			if(bank == 0) time+=100;
			time+=100;
			e++;
			east.pop();
			bank=0;
		}
		else if(e==m)
		{//operate on west
			arrival=west.front();
			
			waiting=arrival-time;
			if(waiting>0) time+=waiting;
			if(bank == 1) time+=100;
			time+=100;
			w++;
			west.pop();
			bank=1;

		}
		else if(west.front() < east.front())
		{//operate on west
			arrival=west.front();
			
			waiting=arrival-time;
			if(waiting>0) time+=waiting;
			if(bank == 1) time+=100;
			time+=100;
			w++;
			west.pop();
			bank=1;

		}
		else if(east.front()<west.front())
		{//operate on east
			arrival=east.front();
			
			waiting=arrival-time;
			if(waiting>0) time+=waiting;
			if(bank == 0) time+=100;
			time+=100;
			e++;
			east.pop();
			bank=0;

		}
	}
	
	// Output the result
	cout<<time<<endl;

	return 0;
}