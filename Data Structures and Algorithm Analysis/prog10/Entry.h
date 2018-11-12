#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_ENTRY
#define H_ENTRY

#define ID_SZ    3      // size of key
#define ITEM_SZ 24      // max size for item description 
#define TBL_SZ  31      // default size for hash table
#define FREE   "$$$"    // indicates empty spot in hash table

// entry in hash table

struct Entry {
    string key,   // key
           desc;  // description
    unsigned num; // no of copies

    //constructor
    Entry ( const string& k = FREE, const string& d = "",
        const unsigned& n = 0 ) : key ( k ), desc ( d ),
        num ( n ) { }
};
#endif
