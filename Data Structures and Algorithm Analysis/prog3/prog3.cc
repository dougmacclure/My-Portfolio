//********************************************************
//Name: Doug MacClure
//Assignment 3
//Due: 2/7/2013
//********************************************************

#include "/home/onyuksel/courses/340/progs/13s/p3/prog3.h"

using namespace std;

int main()
{

//initialize input variable 
int upperLimit;

//prompt user for the upper limit of the range of integers on
//which we utilize the sieve of eratosthenes
cout << "Enter the upper limit for the set of primes: ";
cin >> upperLimit;
cout << endl;

//create an empty set of integers with the default key
set<int> primeSet;

//with a for loop, insert all integers from 2 to upperLimit
//into the set, making use of the insert() member function
//which automatically resizes the set
for(int i = 2; i < upperLimit; i++)
	primeSet.insert(i);

//call the sieve() function to trim all composite integers within
//the set primeSet
sieve(primeSet, upperLimit);

//cal the print_primes() function to print the set in the desired format
print_primes(primeSet);
return 0;
}






