#include "/home/onyuksel/courses/340/common/340.h"

using namespace std;

#ifndef H_PROG8
#define H_PROG8

#define SEED 1      // seed for RNG
#define N 100       // tot num of rand ints

// class to generate rand nums
class RND {
private:
    int seed;   
public:
    RND ( const int& s = SEED ) : seed ( s ) { srand ( seed ); }
    int operator ( ) ( ) { return rand ( ) % N + 1; }
};

#define LSIZE 16    // max num of elems printed on single line
#define WSIZE 4     // allocated size of elem on printout

int SZ;             // size of vector/tree

// macro to print size
#define COUT_SZ cout << "size = " << setw ( 3 ) << SZ << " :"

// class to print elems on stdout
template < class T > void print ( T& x )
{
    static int cnt = 0;

    cout << setw ( WSIZE ) << x; cnt++;
    if ( cnt % LSIZE == 0 || cnt == SZ ) cout << "\n            ";
    if ( cnt == SZ ) cnt = 0;
}
#endif
