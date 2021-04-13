#include <iostream>
#include <map>
using namespace std;


typedef pair<int,int> PII;

long long NumofPaths(int m,int n, map<PII,long long>& paths)
{
	
	
	if(paths.find(PII(m,n))==paths.end())
	{
		
		if (m==1 || n==1)
		{
			
			return 1;
		}
		
			
		paths[PII(m,n)]=(NumofPaths(m-1,n,paths)+ NumofPaths(m,n-1,paths))%4201337;
		
		return paths[PII(m,n)];
			
	}
	else{
		
		return paths[PII(m,n)];
	}

}

int main() {
    // Good luck on your final morning problem! 
    // Great job getting through the semester!

    int m,n;
    

    
    map< PII , long long> paths;

  

    cin>>m>>n;

    cout<<NumofPaths(m+1,n+1,paths)<<endl;;
    


    return 0;
}