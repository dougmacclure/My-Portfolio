/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 4
   PROGRAMMER: Doug MacClure
   LOGON ID:   z0125061
   DUE DATE:   10/18/12

   FUNCTION:   This program tests the functionality of the MyString
               class.
*********************************************************************/  

#include <iostream>
#include <cstring>
#include "MyString.h"

using std::cin;
using std::cout;
using std::endl;

int main()
   {
   cout << "Testing default constructor\n\n";

   MyString s1;
   
   cout << "s1: " << s1 << endl;   
   cout << "s1 size: " << s1.size() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
   
   cout << "Testing second constructor\n\n";
   
   MyString s2 = "some text";
   
   cout << "s2: " << s2 << endl;   
   cout << "s2 size: " << s2.size() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
   
   cout << "Testing size limit on second constructor\n\n";
   
   MyString s3 = "This is a really long string and not all of it will actually end up in the array, but that is okay";
   
   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing write form of subscript operator\n\n";
   
   s2[0] = 'S';
   s2[5] = 'T';
      
   cout << "Testing read form of subscript operator\n\n";
   
   cout << "s2: ";
   for (int i = 0; i < s2.size(); i++)
      cout << s2[i];
   cout << endl << endl;

   cout << "Testing conversion to C string\n\n";
   
   char ar[81];
   
   strcpy(ar, s2.c_str());
   
   cout << "s2 as C string: " << ar << endl << endl;

   cout << "Testing equality operators\n\n";

   MyString s4 = "Some Text";
   
   cout << "s2 and s4 are " << ((s2 == s4) ? "equal\n" : "not equal\n");
   cout << "s3 and s4 are " << ((s3 == s4) ? "equal\n" : "not equal\n");
   cout << "s4 and \"Some Text\" are " << ((s4 == "Some Text") ? "equal\n" : "not equal\n");
   cout << "\"More Text\" and s4 are " << (("More Text" == s4) ? "equal\n" : "not equal\n");
   cout << endl;

   cout << "Testing clear() method\n\n";

   s3.clear();
   
   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   
   return 0;
   }

