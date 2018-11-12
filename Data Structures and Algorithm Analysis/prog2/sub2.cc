//**************************************************************
// ASSIGNMENT:  Assignment #2
// AUTHOR:      Doug MacClure
// LOGON ID:    z0125061
// DUE DATE:    1/30/13
//
// PURPOSE:     Subroutines for Assignment #2 
// 
//**************************************************************/

#include "/home/onyuksel/courses/340/progs/13s/p2/prog2.h"
#include "/home/onyuksel/courses/340/common/340.h"

typedef vector<int>::iterator VI;
typedef vector<int>::const_iterator VCI;

/****************************************************************

FUNCTION: Vectors()

ARGUMENTS: vector<int>& v1, vector<int> &v2, int s1, int s2

RETURNS: void

NOTES:   Fills two vectors with random numbers with the RNG.

****************************************************************/

void Vectors(vector<int> &v1, vector<int> &v2, int s1, int s2)

{
//use passed in seed value to initialize a new sequence of the RNG
srand(s1);

//loop through v1, and pass in a new random number to each element
for(VI i = v1.begin(); i != v1.end(); i++)

	{
	
	//normalize the range of random numbers to be between
	//1 and HIGH
	*i= (rand() % HIGH + 1);
		
	}	 

//repeat the above steps, except using a new seed value for v2
srand(s2);

for(VI i = v2.begin(); i != v2.end(); i++)

	{
	
	*i = (rand() % HIGH + 1);
	
	}

}


/****************************************************************

FUNCTION:  linearSearch() 

ARGUMENTS: const vector<int> &v, int x

RETURNS: bool

NOTES: Checks whether the passed in int x is within the vector v

****************************************************************/


bool linearSearch(const vector<int> &v, int x)

{

//pass in the position of the first instance of int x within vector v
//if it doesn't exist, then we get VCI i = v.end() by utilizing
//the STL function find() for the container vector<>
VCI i = find(v.begin(), v.end(), x);

//if i "points" to an element within v, then return true, else return false
return (i != v.end() ? true : false);

}


/****************************************************************

FUNCTION:  binarySearch() 

ARGUMENTS: const vector<int> &v, int x

RETURNS: bool

NOTES: Checks whether the passed in int x within the vector v

****************************************************************/

bool binarySearch(const vector<int> &v, int x)

{

//return the result of utilizing the binary_search() function for the
//vector container when we have it check between v.begin() and v.end() for 
//any instance of int x
return binary_search(v.begin(), v.end(), x);

}


/****************************************************************

FUNCTION:  search() 

ARGUMENTS: const vector<int> &v1, const vector<int> $v2, bool (*f)(const vector<int> &, int)

RETURNS: int

NOTES: Counts the number of elements of vector v2 that are within vector v1.

****************************************************************/

int search(const vector<int> &v1, const vector<int> &v2, bool (*f)(const vector<int> &, int))

{

int successSearch = 0;

//loop through v2 
for(VCI i = v2.begin(); i != v2.end(); i++)
	
	//if the result of calling the passed in function is true 
	if(f(v1, *i)) 
	
		//increment successSearch by one
		successSearch++;

//outside of loop, return the number of times we incremented successSearch
return successSearch;
	
}

/****************************************************************

FUNCTION:  sortVector() 

ARGUMENTS: vector<int> &v

RETURNS: void

NOTES: Sorts the passed in vector v with the STL sort() function.

****************************************************************/

void sortVector(vector<int> &v)

{

//use sort() to sort the passed in vector in ascending order from
//v.begin() to v.end()
sort(v.begin(), v.end());

}


/****************************************************************

FUNCTION:  printVector() 

ARGUMENTS: const vector<int> &v

RETURNS: void

NOTES: Prints all of the elements of the vector v in accordance
to the required format.

****************************************************************/

void printVector(const vector<int> &v)

{
cout << endl << endl;

//loop through vector v
for(unsigned i = 0; i < v.size(); i++)

	{

	//print the element with a minimum field width ITEM_W
	cout << fixed  << internal << setw(ITEM_W) << v[i] << " ";	

	//if we have printed NO_ITEMS elements or are at the 
	//end of vector v, print a newline
	if( (i+1) % NO_ITEMS == 0 || i + 1 == v.size())
	
		cout << endl;
	
	}

}


/****************************************************************

FUNCTION:  printStat() 

ARGUMENTS: int totalSucCnt, int vectorSz

RETURNS: void

NOTES: Prints the desired statistics produced from calling search()

****************************************************************/

void printStat(int totalSucCnt, int vectorSz)

{

//Print the average number of comparisons, which is the size of vector2 in main() 
//aka, the passed in vectorSz
cout << "        Average Number of Comparisons = " << vectorSz << endl;

//Print the percentage of successful searches, which is number of successful searches
//divided by size of vector2, quantity times 100.
cout << "        Percent of Successful Searches = " << "%" << fixed << setprecision(2)
	<< ((float)totalSucCnt/vectorSz)*100 << endl;


}

