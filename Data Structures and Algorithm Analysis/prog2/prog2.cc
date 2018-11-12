/***********************************************

Name:  Doug MacClure
CSCI340-3 Assignment #2
Due:   1/30/12

*********************************************/

#include "/home/onyuksel/courses/340/common/340.h"
#include "/home/onyuksel/courses/340/progs/13s/p2/prog2.h"

int main()
{

//the input vector
vector<int> vector2(TEST_ARR_SIZE);
//the test vector
vector<int> vector1(ARR_SIZE);
//an integer that stores the result of the search() subroutine
int numSuccess;

//call the subroutine Vectors() to fill the input and test vectors with 
//random numbers
Vectors(vector1, vector2, SEED1, SEED2);

//print the unsorted elements of the test vector
cout << endl << "Random Numbers Before Sorting: ";
printVector(vector1);

//call the sortVector() subroutine to sort the test vector in ascending order
sortVector(vector1);

//print the sorted elements of the test vector
cout << endl << "Random Numbers After Sorting: ";
printVector(vector1);

//print the unsorted elements of the input vector
cout << endl << "Random Numbers Searched: ";
printVector(vector2);

//call the search subroutine to find how many elements of the input vector
//are within the test vector by passing in the linearSearch subroutine
//and storing the result in numSuccess, then print the results with printStat
numSuccess = search(vector1, vector2, linearSearch);
cout << endl << "Linear Search:" << endl;
printStat(numSuccess, vector2.size());

//same as above, except pass in the binarySearch subroutine
numSuccess = search(vector1, vector2, binarySearch);
cout << endl << "Binary Search:" << endl;
printStat(numSuccess, vector2.size());


return 0;

}

