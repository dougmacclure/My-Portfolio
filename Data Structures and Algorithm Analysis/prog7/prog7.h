//FILE: prog7.h
//Doug MacClure
//CSCI340-3




#include "/home/onyuksel/courses/340/common/340.h"
#include "binTree.h"

#ifndef H_PROG7
#define H_PROG7

using namespace std;

template <class T> void print ( T& x );
template <class T > void increase ( T& x );
template <class T> void decrease ( T& x );

template <class T> void isEmpty ( const binTree < T >& );
template <class T> void header ( const binTree < T >& );

template <class T> void inOrder ( binTree < T >&, const string& );
#endif
