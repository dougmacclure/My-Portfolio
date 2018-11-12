#include "/home/onyuksel/courses/340/progs/13s/p8/prog8.h"
#include "binSTree.h"

// This program generates bunch of rand ints in given range
// and stores them in vector, and it also inserts them in
// binary search tree. Then, removes all leaves in tree and
// repeat this process until tree becomes empty.

int main ( )
{
    vector < int > v ( N );  // holds rand ints
    binSTree < int > t;      // binary search tree ( BST )

    // generate rand ints
    generate ( v.begin ( ), v.end ( ), RND ( ) );

    // printout contents of vector
    SZ = v.size ( ); COUT_SZ;
    for_each ( v.begin ( ), v.end ( ), print < int > ); cout << endl;

    // insert ints in vector into BST
    for ( unsigned i = 0; i < v.size ( ); i++ ) t.insert ( v [ i ] );

    // remove leaves of BST until it becomes empty
    bool flag = true;        // to check if BST empty
    while ( flag )
    {
        // printout contents of BST
        SZ = t.size ( ); COUT_SZ;
        t.inOrder ( print < int > ); cout << endl;

        // remove all leaves of BST
        flag = false;
        for ( unsigned i = 0; i < v.size ( ); i++ )
            if ( t.remove ( v [ i ] ) ) flag = true;
    }

    return 0;
}
