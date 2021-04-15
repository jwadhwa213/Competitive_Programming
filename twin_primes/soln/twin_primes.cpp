#include <iostream>
using namespace std;

bool isPrime(int n)
{ /* This function takes an integer value n as an argument, checks if it is prime or not 
     and returns a boolean value for an answer*/
	
	//a counter to count the number of factors of n
	int count=0;

	if (n==2)
	{
		// this checks if the entered number is 2 and returns true
		return true;
	}
	else if (n>2 && n%2!=0)
	{
		// this else if block counts the number of factors of n and returns true for prime 
		//and false for a non-prime number n
		for(int i=1;i<=n;i+=2)
		{
			// a for loop that runs n times
			if (n%i==0)
			{
				// increase the counter by 1 for every i that is a factor of n
				count+=1;
			}
			if (count==3)
			{
				// return false if the counter reaches 3 because a prime number has only two factors
				// that are 1 and the number itself
				return false;
			}
		}

		if (count==2)
		{
			//check if the counter is equal to 2 after the loop runs n times and return true
			return true;
		}
	}
	else
	{
		//this block runs if the entered number is even or less than 2
		return false;
	}
	return false;
}
void twinPrimes(int k)
{/*This function takes an integer k as an argument and prints the first k twin prime pairs */
	
	//initializing a boolean array to store the result of function isPrime(int n) and an integer array
	// to store the corresponding numbers
	bool arrPrime[2]={false,false};
	int numarr[2]={0,0};
	//initializing a counter to count the number of pairs printed
	// we start checking for prime numbers with j=3 and increment in the while loop
	int count=0,j=3;


	while(count<k)
	{
		//This while loop finds and prints the first k twin prime pairs
	
		//storing the result of the last value checked at array index 0
		arrPrime[0]=arrPrime[1];
		// calling the isPrime function for value j and storing the result at array index 1
		arrPrime[1]=isPrime(j);

		//storing the last value checked at array index 0
		numarr[0]=numarr[1];
		//storing the present value of j at array index 1
		numarr[1]=j;

		if(arrPrime[0]==true && arrPrime[1]==true)
		{
			//check if the arrPrime array has true at both the indices,i.e 0 and 1, print the twin prime
			//pair and increment the counter by 1
			count+=1;
			cout<<numarr[0]<<" "<<numarr[1]<<endl;
		}
		// increment j by 2 to check the next odd number
		j+=2;
	}
}

int main()
{/*This is the main function of this program. This takes in the input and calls the isPrime() function
   or twinPrime() function to compute the desired result.*/
	
	// initialising the variables
	char choice;
	int num;
	bool prime;

	// taking in the input.
	cin>>choice>>num;


	if(choice == 'p')
	{
		//This if block runs if the entered character is 'p'

		//calling the isPrime() function on the entered number (num)
		prime=isPrime(num);

		
		if(prime==true)
		{
			//if the isPrime function returned True, then print "prime"
			cout<<"prime"<<endl;
		} 
		else
		{
			// if the isPrime function returned false then print "not prime"
			cout<<"not prime"<<endl;
		}
	}

	if(choice=='t')
	{
		// calling function twinPrimes() if the entered choice is 't'
		twinPrimes(num);

	}
	return 0;

}