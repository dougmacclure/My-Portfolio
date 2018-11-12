#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_PROG9
#define H_PROG9

// data files

#define D1 "/home/onyuksel/courses/340/progs/13s/p9/prog9.d1"
#define D2 "/home/onyuksel/courses/340/progs/13s/p9/prog9.d2"
#define D3 "/home/onyuksel/courses/340/progs/13s/p9/prog9.d3"

#define INT_SZ 4    // width of integer
#define FLT_SZ 7    // width of floating-pt number
#define STR_SZ 12   // width of string

#define INT_LN 15   // no of integers on single line
#define FLT_LN 9    // no of floating-pt nums on single line
#define STR_LN 5    // no of strings on single line

// function and class prototypes

// stores items from input file into vector
template < class T >
void get_list ( vector < T >&, const char* );

// construct heap from items in vector
template < class T, class P >
void construct_heap ( vector < T >&, P );

// class to compare absolute values
template <class T> class abs_less {
public:
    bool operator ( ) ( const T&, const T& ) const;
};

// structure to print items in heap, where T is data type of items,
// W is allocated size in printout, and L is max num of items printed
// on single line

template < class T, const int W, const int L >
struct print_list {
    int sz, cnt; // size of heap and counter for printing
    print_list ( const int&, const int& = 0 ); // constructor
    void operator ( ) ( const T& );
};
#endif
