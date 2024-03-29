//**************************************************************
// FILE:	quicksort.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	12/5/12
//
// PURPOSE: Header file for the class definitions for the 
// Deque class
//**************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>

using namespace std;


template <class T>
bool lessThan(const T&, const T&);

template <class T>
bool greaterThan(const T&, const T&);

template <class T>
void buildList(vector<T>&, const char*);

template <class T>
void printList(const vector<T>&, int, int);

template <class T>
void sortList(vector<T>&, bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>&, int, int, bool(*compare)(const T&, const T&));

template <class T>
int partition(vector<T>&, int, int, bool(*compare)(const T&, const T&));


/****************************************************************

FUNCTION: lessThan()

ARGUMENTS: const T& item1, const T& item2

RETURNS: bool

NOTES: returns true if item1 < item2 and false if not

****************************************************************/

template <class T>
bool lessThan(const T& item1, const T& item2)
{

return item1 < item2;

}

/****************************************************************

FUNCTION: greaterThan()

ARGUMENTS: const T& item1, const T& item2

RETURNS: bool

NOTES: returns true if item1 > item2 and false if not

****************************************************************/

template <class T>
bool greaterThan(const T& item1, const T& item2)
{

return item1 > item2;

}


/****************************************************************

FUNCTION: buildList()

ARGUMENTS: vector<T>& set, const char* fileName

RETURNS: void

NOTES: reads input from file into template vector

****************************************************************/

template <class T>
void buildList(vector<T>& set, const char* fileName)
{

T item;
ifstream inFile;

inFile.open(fileName);

if(inFile.fail())

	{
	
	cout << endl <<"Unable to open file." << endl;
	exit(1);

	}

inFile >> item;

	while(inFile)
	
	{
	
	//use vector function push_back to build our list with each read
	//from the file
	set.push_back(item);
	inFile >> item;
	
	}

inFile.close();

}

/****************************************************************

FUNCTION: printList()

ARGUMENTS: vector<T>& set, int itemWidth, intnumPerLine

RETURNS: void

NOTES: prints the list according to passed in specifications.
itemWidth tells use the field width for each set[] element
and numPerLine tells us how many set[] elements to print per line.

****************************************************************/

template <class T>
void printList(vector<T>& set, int itemWidth, int numPerLine)
{

cout << endl;

for (int i = 0; i < (int)set.size(); i++)

	{
	
	//if we have printed numPerLine elements, print a newline
	if(i % numPerLine == 0)
	
		{

		cout << endl;

		}
	//print out the set element with the passed in field width
	cout << setw(itemWidth) << set[i];
	
	}


}

/****************************************************************

FUNCTION: sortList()

ARGUMENTS: vector<T>& set, bool (*compare)(const T&, const T&)

RETURNS: void

NOTES: calls quicksort, passing in the subscript of the first and last 
elements, and a pointer to the compare function

****************************************************************/

template <class T>
void sortList(vector<T>& set, bool(*compare)(const T&, const T&))
{

quickSort(set, 0, (int) set.size()-1, compare);

}




/****************************************************************

FUNCTION: quickSort()

ARGUMENTS: vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)

RETURNS: void

NOTES: First calls the partition function to find the pivotPoint, then calls itself recursively
twice, the first where the list is sorted from the beginning of the list to the position to
the "left" of the pivot, and again where the list is sorted from the element to the"right" of the
pivot to the effective "end" of the list. Nothing is done if the passed if start >= end.
****************************************************************/

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))

{

int pivotPoint;

if (start < end)

	{
	
	//get the pivot point
	pivotPoint = partition(set, start, end, compare);
	//sort the first sublist
	quickSort(set, start, pivotPoint - 1, compare);
	//sort the second sublist
	quickSort(set, pivotPoint +	1, end, compare);
	
	}

}

/****************************************************************

FUNCTION: partition()

ARGUMENTS: vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)

RETURNS: int

NOTES: Picks a pivot value within set's list, put it at the beginning of the list
then scan through the set, placing values smaller than pivot next to it.  After we
have partitioned our list, find the smallest element in the list, and exchange 
it with the pivot value, so the smallest element is in the first position. 

****************************************************************/

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))

{

int pivotIndex, mid;
T pivotValue, temp;
mid = (start + end) / 2;

//Swap elements start and mid of the vector
temp = set[start];
set[start] = set[mid];
set[mid] = temp;

pivotIndex = start;
pivotValue = set[start];


//loop through set, starting from the item next to the starting element 
for (int scan = start + 1; scan <= end; scan++)

	{
    	//if our set[scan] element is smaller than the pivot, then place it to the right of
	//the pivot and other elts smaller than the pivot
	if (compare(set[scan], pivotValue))

		{
        
		pivotIndex++;
        
		//Swap elements pivotIndex and scan of the vector
		temp = set[pivotIndex];
		set[pivotIndex] = set[scan];
		set[scan] = temp;
		        
		}
		
	}

   //Swap elements start and pivotIndex of the vector
   temp = set[start];
   set[start] = set[pivotIndex];
   set[pivotIndex] = temp;

   //return the new location of the pivot
   return pivotIndex; 

}



#endif


