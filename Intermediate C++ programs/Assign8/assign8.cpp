/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Doug MacClure
   LOGON ID:   z0125061
   DUE DATE:   11/28/12
   
   FUNCTION:   This program tests the functionality of the Deque
               template class.
*********************************************************************/  

#include <iostream>
#include <cstdlib>
#include "Deque.h"

using std::cout;
using std::endl;

int main()
   {
   cout << "Testing creation of empty deque...\n";
   
   Deque<int> deque1;

   cout << "deque 1 is ";

   if (deque1.empty())
      cout << "empty" << endl;
   else
      cout << "not empty" << endl;

   cout << "deque 1 (size " << deque1.size() << "): " << deque1 << endl << endl;

   cout << "Testing push_back() into empty deque...\n";

   deque1.push_back(17);

   cout << "deque 1 is ";
   if (deque1.empty())
      cout << "empty" << endl;
   else
      cout << "not empty" << endl;

   cout << "deque 1 (size " << deque1.size() << "): " << deque1 << endl << endl;

   cout << "Testing push_back() into non-empty deque...\n";

   deque1.push_back(2);
   deque1.push_back(6);
   deque1.push_back(4);

   cout << "deque 1 (size " << deque1.size() << "): " << deque1 << endl << endl;

   cout << "Testing copy constructor...\n";
   
   Deque<int> deque2(deque1);

   cout << "deque 1 (size " << deque1.size() << "): " << deque1 << endl;
   cout << "deque 2 (size " << deque2.size() << "): " << deque2 << endl << endl;

   cout << "Testing clear() of non-empty deque...\n";
   
   deque1.clear();

   cout << "deque 1 (size " << deque1.size() << "): " << deque1 << endl;
   cout << "deque 2 (size " << deque2.size() << "): " << deque2 << endl << endl;

   cout << "Testing clear() of empty deque...\n";

   Deque<int> deque3;

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl;

   deque3.clear();
   
   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl << endl;

   cout << "Testing push_front() into empty deque...\n";

   deque3.push_front(36);

   cout << "deque 3 is ";
   if (deque3.empty())
      cout << "empty" << endl;
   else
      cout << "not empty" << endl;

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl << endl;

   cout << "Testing push_front() into non-empty deque...\n";

   deque3.push_front(41);
   deque3.push_front(75);
   deque3.push_front(28);

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl << endl;

   cout << "Testing assignment operator...\n";

   Deque<int> deque4;

   deque4 = deque3;

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl;
   cout << "deque 4 (size " << deque4.size() << "): " << deque4 << endl << endl;

   deque3.clear();

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl;
   cout << "deque 4 (size " << deque4.size() << "): " << deque4 << endl << endl;

   cout << "Testing assignment to self and swap...\n";

   deque4 = deque4;
   deque3 = deque4;
   deque4.clear();

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl;
   cout << "deque 4 (size " << deque4.size() << "): " << deque4 << endl << endl;

   cout << "Testing chained assignment...\n";

   Deque<int> deque5;

   deque5 = deque4 = deque3;

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl;
   cout << "deque 4 (size " << deque4.size() << "): " << deque4 << endl;
   cout << "deque 5 (size " << deque5.size() << "): " << deque5 << endl << endl;

   cout << "Testing write versions of front() and back()...\n";

   deque3.front() = 16;
   deque5.back() = 82;

   cout << "deque 3 (size " << deque3.size() << "): " << deque3 << endl;
   cout << "deque 4 (size " << deque4.size() << "): " << deque4 << endl;
   cout << "deque 5 (size " << deque5.size() << "): " << deque5 << endl << endl;
   
   cout << "Testing read version of front(), push_back(), pop_front()...\n";

   Deque<int> deque6, deque7;

   srand(20120322);

   for(int i = 0; i < 9; i++)
      deque6.push_back(rand() % 100);

   cout << "deque 6 (size " << deque6.size() << "): " << deque6 << endl << endl;

   for(int i = 0; i < 9; i++)
      {
      int val;

      val = deque6.front();
      deque7.push_back(val);
      deque6.pop_front();
      }

   cout << "deque 6 (size " << deque6.size() << "): " << deque6 << endl;
   cout << "deque 7 (size " << deque7.size() << "): " << deque7 << endl << endl;

   deque6.clear();
   deque7.clear();

   cout << "Testing read version of back(), push_front(), pop_back()...\n";

   for(int i = 0; i < 9; i++)
      deque6.push_front(rand() % 100);

   cout << "deque 6 (size " << deque6.size() << "): " << deque6 << endl << endl;

   for(int i = 0; i < 9; i++)
      {
      int val;

      val = deque6.back();
      deque7.push_front(val);
      deque6.pop_back();
      }

   cout << "deque 6 (size " << deque6.size() << "): " << deque6 << endl;
   cout << "deque 7 (size " << deque7.size() << "): " << deque7 << endl << endl;

   cout << "Testing read versions of front() and back()...\n";

   int val1, val2;

   deque6 = deque7;

   val1 = deque6.front();
   val2 = deque7.front();
   val1 = deque6.front();   // Make sure that front() doesn't remove a value.

   if(val1 == val2)
      cout << "front() works" << endl;
   else
      cout << "front() failure" << endl;

   val1 = deque6.back();
   val2 = deque7.back();
   val1 = deque6.back();   // Make sure that back() doesn't remove a value.

   if(val1 == val2)
      cout << "back() works" << endl;
   else
      cout << "back() failure" << endl;

   cout << "\nTesting destructor...\n";


   return 0;
 }

