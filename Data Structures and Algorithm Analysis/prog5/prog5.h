#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_PROG5
#define H_PROG5

#define SEED 1                   // seed for RNG
#define SIM_TIME ( 30 * 24 * 60 )// total simulation time in minutes
#define SAMPLE_INT 500           // period for sampling intervals

#define MIN_INT_ARR 1            // min interarrival time for customers
#define MAX_INT_ARR 5            // max interarrival time for customers

#define MIN_PICK 1               // min time to pick items in shopping
#define MAX_PICK 20              // max time to pick items in shopping

#define MIN_SERV 1               // min service time in checkout line
#define MAX_SERV 4               // max service time in checkout line

// structure for customer
typedef struct {
    int id;                    // customer id
    int atime, dtime;          // customer arrival and departure times
} cust;

// structure for time event
typedef struct {
    int next_arr, next_dept;   // next arrival and next departure times
} event;

// structure for final statistics
typedef struct {
    long num_dept;             // num of customers departed 
    long tot_shop;             // total shopping times
    int min_shop, max_shop;    // min and max shopping times
} stat;


// class to compare departure times for customers c1 and c2
class cmp {
public:
    bool operator ( ) ( const cust& c1, const cust& c2 ) const;
};

typedef multiset < cust, cmp > MS;
typedef MS :: iterator P;

// initialize values in structures e and s
void init_vars ( event& e, stat& s);

// creates object for arriving customer with id, insert it in multiset ms,
// and updates timing values in structure e
void Arrival ( event& e, const int& id, MS& ms );

// removes object for departing customer from multiset ms, updates timing
// values in structure e, and updates final statistics in structure s
void Departure ( event& e, MS& ms, stat& s );

// updates clock to first occurrence of timing events in structure e
// with given Boolean value of flag
int update_clock ( const event& e, const bool& flag );

// returns next arrival time
int arr_time ( const int& clock );

// returns next departure time
int dept_time ( const int& clock );

// updates final statistics in structure s for customer c
void update_fin_stat ( stat& s, const cust& c );

// prints final statistics in structure s
void print_fin_stat ( stat& s );

// generates random num in range [ low, high ]
int rnd ( const int& low, const int& high );
#endif
