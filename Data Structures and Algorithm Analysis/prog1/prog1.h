#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_PROG1
#define H_PROG1

#define ARR_SIZE 200   // array size

#define NO_ITEMS 12    // num of items printed on line
#define ITEM_W   5     // num of spaces allocated for printed item

#define SEED     1     // seed value for RNG
#define LOW      1     // min value for rnd int
#define HIGH     10000 // max value for rnd int

// routine to generate rand nums for array
void genRndNums ( int [ ] );

// routine to print elems of array
void printArr ( int [ ] );
#endif
