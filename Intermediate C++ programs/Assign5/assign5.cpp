/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 5
   PROGRAMMER: Doug MacClure
   LOGON ID:   z0125061
   DUE DATE:   10/25/12

   FUNCTION:   This program tests the functionality of the MyString
               class.
*********************************************************************/  

#include <iostream>
#include <stdexcept>
#include <cstring>
#include "MyString.h"

using std::cin;
using std::cout;
using std::endl;
using std::out_of_range;

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
   
   cout << "Testing long string with second constructor\n\n";
   
   MyString s3 = "This is a really long string and this time all of it will actually end up in the array - pretty neat, huh?";
   
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
   cout << endl;

   cout << "Testing capacity()\n\n";

   cout << "s3 capacity: " << s3.capacity() << endl << endl;
   
   cout << "Testing copy constructor\n\n";
   
   MyString s5 = s4;
   
   cout << "s5: " << s5 << endl;   
   cout << "s5 size: " << s5.size() << endl;
   cout << "s5 capacity: " << s5.capacity() << endl;
   cout << "s5 is " << ((s5.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing assignment operator\n\n";
   
   s3 = s5;

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << endl;

   s3 = "a different string";

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << endl;

   cout << "Testing self-assignment\n\n";

   s3 = s3;

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << endl;

   cout << "Testing chained assignment\n\n";

   s1 = s4 = "Hello, world";

   cout << "s4: " << s4 << endl;
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << endl;

   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << endl;
   cout << "s1 capacity: " << s1.capacity() << endl;
   cout << endl;

   cout << "Testing string concatenation\n\n";

   MyString s6("gone ");
   MyString s7("fishing");

   cout << "MyString plus Mystring: " << s6 + s7 << endl;
   cout << "MyString plus C string: " << s7 + " hole" << endl;
   cout << "C string plus MyString: " << "fly " + s7 << endl;
   cout << "One more: " << s6 + "down to the " + s7 + " hole" << endl << endl;
   
   cout << "Testing write form of at() method\n";
   
   try
      {
      s2.at(0) = 's';
      s2.at(5) = 't';
      s2.at(-1) = 'H';
      }
   catch (out_of_range orex)
      {
      cout << "Caught exception: "<< orex.what() << endl << endl;
      }
      
   try
      {
      cout << "Testing read form of at() method\n\n";
   
      cout << "s2: ";
      for (int i = 0; i <= s2.size(); i++)
         cout << s2.at(i);
      }
   catch (out_of_range orex)
      {
      cout << endl << "Caught exception: "<< orex.what() << endl;
      }

   return 0;
   }

