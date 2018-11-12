//************************************************
// FILE: prog6.h
// Assignment6
// PURPOSE: contains function prototypes and containers
// used in prog6.cc  
//************************************************


#ifndef PROG6_H
#define PROG6_H

#include "binTree.h"
#include "/home/onyuksel/courses/340/common/340.h"
using namespace std;

template < class T > void print ( T& );
template < class T > void increase ( T& );
template < class T > void decrease ( T& );
template < class T > void isEmpty ( const binTree < T >& );
template < class T > void header ( const binTree < T >& );
template < class T > void inOrder ( binTree < T >&, const string& );
template < class T > void preOrder ( binTree < T >&, const string& );
template < class T > void postOrder ( binTree < T >&, const string& );

const vector<int> A{ 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15 };
const vector<float> B{ 0.5, 1.75, -3, 4.25, 5.50, -6.75, 8, 9.25, -10.5 };
const vector<string> C{ "This", "is", "a", "list", "of", "string", "objects." };
#endif
