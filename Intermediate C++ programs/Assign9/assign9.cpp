/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Doug MacClure
   LOGON ID:   z0125061
   DUE DATE:   12/5/12
 
   FUNCTION:   This program builds and sorts lists using the quick
               sort algorithm.
*********************************************************************/  

#include <iostream>
#include <vector>
#include <string>
#include "quicksort.h"

using std::cout;
using std::string;
using std::vector;

// Data files

#define D1 "/home/turing/t90kjm1/CS241/Data/Fall2012/Assign9/data9a.txt"
#define D2 "/home/turing/t90kjm1/CS241/Data/Fall2012/Assign9/data9b.txt"
#define D3 "/home/turing/t90kjm1/CS241/Data/Fall2012/Assign9/data9c.txt"

// Output formatting constants

#define INT_SZ 4    // width of integer
#define FLT_SZ 7    // width of floating-pt number
#define STR_SZ 12   // width of string

#define INT_LN 15   // no of integers on single line
#define FLT_LN 9    // no of floating-pt nums on single line
#define STR_LN 5    // no of strings on single line

int main()
   {
   vector<int> v1;      // vector of integers
   vector<float> v2;    // vector of floating-pt nums
   vector<string> v3;   // vector of strings

   // print header message
   cout << "*** CSCI 241: Assignment 9 - Output ***\n\n";

   // sort and print first list

   cout << "First list - ascending order:\n\n";
   buildList(v1, D1);
   sortList(v1, &lessThan);
   printList(v1, INT_SZ, INT_LN);

   v1.clear();

   cout << "\nFirst list - descending order:\n\n";
   buildList(v1, D1);
   sortList(v1, &greaterThan);
   printList(v1, INT_SZ, INT_LN);

   // Sort and print second list

   cout << "\nSecond list - ascending order:\n\n";
   buildList(v2, D2);
   sortList(v2, &lessThan);
   printList(v2, FLT_SZ, FLT_LN);

   v2.clear();

   cout << "\nSecond list - descending order:\n\n";
   buildList(v2, D2);
   sortList(v2, &greaterThan);
   printList(v2, FLT_SZ, FLT_LN);

   // Sort and print third list

   cout << "\nThird list - ascending order:\n\n";
   buildList(v3, D3);
   sortList(v3, &lessThan);
   printList(v3, STR_SZ, STR_LN);

   v3.clear();

   cout << "\nThird list - descending order:\n\n";
   buildList(v3, D3);
   sortList(v3, &greaterThan);
   printList(v3, STR_SZ, STR_LN);

   // print termination message
   cout << "\n*** End of program execution ***\n";

   return 0;
   }

