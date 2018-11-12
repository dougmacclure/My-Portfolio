#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_PROG3
#define H_PROG3

#define NO_ITEMS 16 // no of primes printed on single line
#define ITEM_W   4  // no of spaces allocated for each prime

// routine for Sieve of Eratosthenes algorithm
void sieve ( set < int >&, int );

// prints out set of primes
void print_primes ( const set < int >& );
#endif
