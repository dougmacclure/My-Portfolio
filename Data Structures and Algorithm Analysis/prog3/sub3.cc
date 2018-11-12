//***********************************/
//Name: Doug MacClure
//Assignment 3
//Due: 2/7/2013
//***********************************/


#include "/home/onyuksel/courses/340/progs/13s/p3/prog3.h"

typedef set<int>::iterator SI;

using namespace std;


/************************************
/CLASS: print
/
/NOTES: Used to print the set primeSet
************************************/

class print{

private:
unsigned size, count;
public:

//******************************************************
//FUNCTION:  print()
//ARGUMENTS: const unsigned &u, &c
//RETURNS: void
//NOTES: Print's constructor, with default arguments assigned
//******************************************************/

print(const unsigned &u = 0, const unsigned &c = 0):size(u),count(c){}
void operator()(const int &x)	
	{ 

	//print each item with a minimum field width of ITEM_W, then increment count
	cout << setw(ITEM_W) << x;
	count++;
	//if we have printed NO_ITEMS elements, or we are at the end of the set
	//print a new line
	if(count % NO_ITEMS == 0 || count == size)
		cout << endl;
	}
};


/*********************************************************
/FUNCTION: con0modm()
/ARGUMENTS: int &x, int &y
/RETURNS: bool
/NOTES: if x is congruent to 0 modulo y and x != y, then
/return true, otherwise return false.
********************************************************/

bool con0modm(const int&x, int&y)
{

if( x != y && x % y == 0)

return true;

else 

return false;
}


/********************************************************
/FUNCTION: sieve()
/ARGUMENTS: set<int> &s, int n
/RETURNS: void
/NOTES: In the outside for loop, iterate through each
/integer up to m*m, while within the inside loop
/for each m, check if any element in the set is divisible
/by m, and not equal to m.  If so, delete said element.
********************************************************/


void sieve( set<int> &s, int n)
{

//Initialize our set iterator to beginning of set
SI s1 = s.begin();

//beginning with 2, increment m by 1 until m*m =n
for(int m = 2; m*m <= n; m++)
	{
	//while the iterator is "pointing" to an element within the set	
	while(s1 != s.end())
		{
		//check if the element is divisible by m and not equal to m
		if(con0modm(*s1, m))
			{
			//if the condition is true, erase the element with the
			//set member function erase(), then increment the iterator to the
			//next element
			s.erase(s1);
			s1++;
			}
		else
			//otherwise move onto the next element
			s1++;
		}

	//after we have looped through the set once, put the iterator s1 back to s.begin()

	s1 = s.begin();
	
	}

}
//********************************************************
//FUNCTION: print_primes()
//ARGUMENTS: const set<int> &s
//RETURNS: void
//NOTES: Using the for_each() STL function, print each
//element of the set s with the class print's overloaded 
//() operator, passing in the size of the set to print's constructor.
//********************************************************
void print_primes(const set<int> &s)
{
for_each(s.begin(), s.end(), print(s.size()));
}

