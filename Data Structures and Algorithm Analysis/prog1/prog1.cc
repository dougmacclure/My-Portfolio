
/***************************************************************
/
/
/Name:  Doug MacClure
/Assignment #1
/Due: 1/22/2013
/
/
***************************************************************/





#include "/home/onyuksel/courses/340/common/340.h"
#include "/home/onyuksel/courses/340/progs/13s/p1/prog1.h"

using namespace std;

int main()

{
//initializes an int array of size ARR_SIZE
int arr[ARR_SIZE];

//call the genRndNums() subroutine to fill arr with random integers
genRndNums(arr);

//use the routine sort() defined in STL to sort the array arr in ascending order 
sort(arr, arr + ARR_SIZE);

//call printArr() to print arr
printArr(arr);

return 0;
}

/****************************************************************

FUNCTION: genRndNums()

ARGUMENTS: int arr[]

RETURNS: void

NOTES: Calls the RNG with the seed value SEED, then generates a random
number ARR_SIZE times, and places each within the array arr.

****************************************************************/


void genRndNums(int arr[])

{

//with the given seed value we can generate random numbers
srand(SEED);

for(int i = 0; i < ARR_SIZE; i++)

	//in each i-th position of the array arr, we place a random
	//number with rand(), keeping it in the range of LOW and HIGH
	//by modularly dividing rand() by (HIGH - LOW + 1), then adding
	//LOW to the resulting integer

	arr[i] = rand() % (HIGH - LOW + 1) + LOW;
	
}


/****************************************************************

FUNCTION: printArr()

ARGUMENTS: int arr[]

RETURNS: void

NOTES: Using the for() routine, we print each individual element
in an ordered way.

****************************************************************/

void printArr(int arr[])

{

for (int i = 0; i < ARR_SIZE; i++)

	{
	//if we are at the NO_ITEMS'th position in the array, we want to 
	//print a newline
	if(i % NO_ITEMS == 0)
	
		{
		
		cout << endl;
		
		}
		
	//print the i-th arr element to have a minimum field width of ITEM_W

	cout << setw(ITEM_W) << arr[i];	   
	
	}

cout << endl;

}

