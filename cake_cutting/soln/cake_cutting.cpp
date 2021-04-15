#include <iostream>
#include <math.h>
using namespace std;

int main(){
	// declare your variables
	int b,s;
	cin>>b>>s;
	double q=log(s)/log(b);
	int p=log(s)/log(b);

	if(p==q)
		cout<<"GOOD"<<endl;
	else
		cout<<"BAD"<<endl;
	// read the input

	// solve, good luck!

	return 0;
}
