//**********************************************************************************
// Doug MacClure
//
// Assignment 5
//
// DUE: 2/26/13
//
//*********************************************************************************


#include "/home/onyuksel/courses/340/progs/13s/p5/prog5.h"

using namespace std;

int main()
{

//create empty multiset to hold instore customers that is ordered with respect to the function cmp
MS store;

//activate the RNG
srand(SEED);

//start the simulation clock, and prepare for first customer arrival
int clock = 0;
int id = 1;
stat storeStats;
event storeEvents;
init_vars(storeEvents, storeStats);

//while the simulation clock hasn't exceeded SIM_TIME
while(clock <= SIM_TIME)

	{
	
	//if the next event is an arrival, where the sim clock is equal to the next_arr data member of the event struct 
	if(clock >= storeEvents.next_arr)
		{
		
		//call Arrival() to update store, next arrival time, and next departure time
		Arrival(storeEvents, id, store);

		}

	//if the store is not empty and the sim clock is equal to the next_dept data member of the event struct
	if(clock >= storeEvents.next_dept && (!store.empty()))

		{

		//call Departure() to remove customer from store, update next_arr and next_dept and update stats
		Departure(storeEvents, store, storeStats);
		}	
	
	//move the clock forward with respect to update_clock()
	clock =	update_clock(storeEvents, store.empty());
	//update id to signify a new customer if we have a new arrival
	id++;
	


	}

print_fin_stat(storeStats);

return 0;
}


//*******************************************************************************************
// FUNCTION: init_vars()
// ARGUMENTS: event &e, stat &s
// RETURNS:v void
// NOTES: Called once to initialize the data members for the passed in event and stat structs
// such that the Arrival() routine is called when main() while loop begins
//*******************************************************************************************

void init_vars(event &e, stat &s)
{

e.next_arr = 0;
e.next_dept = SIM_TIME + 1;
s.num_dept = 0;
s.tot_shop = 0;
s.min_shop = SIM_TIME;
s.max_shop = 0;

}

//********************************************************************************************
// FUNCTION:  Arrival()
// ARGUMENTS: event &e, const int &id, MS &ms
// RETURNS:  void
// NOTES:  Is called when simulation clock is equal to e.next_arr, so e.next_arr is current clocktime.
// Create new cust object with proper date members, insert into ms, then update e.next_arr & e.next_dept
//********************************************************************************************


void Arrival(event &e, const int &id, MS &ms)
{

int tempClock = e.next_arr;
cust c;
c.id = id;
c.atime = tempClock;
c.dtime = dept_time(e.next_arr);
//insert cust object into ms
ms.insert(c);

//call arr_time to set e.next_arr by passing in current time
e.next_arr = arr_time(e.next_arr);
P p = ms.begin();
c = *p;

//make sure e.next_dept is the first customer in the set, with the smallest dtime
e.next_dept = c.dtime;
}

//*******************************************************************************************
// FUNCTION:  Departure()
// ARGUMENTS: event &e, MS &ms, stat &s
// RETURNS:  void
// NOTES: Is called when simulation clock <= e.next_dept, which corresponds to the first customer in
// ms.  Call update_fin_stat to update statistics of given customer.
//*******************************************************************************************


void Departure(event &e, MS &ms, stat &s)
{

P p = ms.begin();
//temporarily first element of ms's cust data members to pass into update_fin_stat
cust c = *p;
//delete cust object from store
ms.erase(p);

//if the store is notempty then update e.next_dept, otherwise don't update
if( ms.empty() != true )
	e.next_dept = dept_time(e.next_dept);

//call udpate_fin_stat () to save stats of customer
update_fin_stat(s, c);
}


//*******************************************************************************************
// FUNCTION:  arr_time()
// ARGUMENTS: const int& clock
// RETURNS: int
// NOTES: Used to update storeEvents.next_arr, by setting it equal to the current clocktime plus
// a random number normalized between MIN_INT_ARR and MAX_INT_ARR
//*******************************************************************************************


int arr_time(const int& clock)
{
int RND = rnd(MIN_INT_ARR, MAX_INT_ARR);
return clock + RND;

}


//******************************************************************************************
// FUNCTION: dept_time()
// ARGUMENTS: const int &clock
// RETURNS: int
// NOTES:  Used to update storeEvents.next_dept by setting it equal to the current clocktime
// plus two random numbers, one normalized between MIN_PICK & MAX_PICK and the other between
// MIN_SERV & MAX_SERV
//*****************************************************************************************

int dept_time(const int& clock)
{

int RNDPICK = rnd(MIN_PICK, MAX_PICK);
int RNDSERV = rnd(MIN_SERV, MAX_SERV);

return clock + RNDPICK + RNDSERV;

}

//*****************************************************************************************
// FDUNCTION: update_clock()
// ARGUMENTS: const event &e, const bool &flag
// RETURNS: int
// NOTES: update_clock is called in main() to move simulation clock forward
//
//*****************************************************************************************

int update_clock(const event &e, const bool &flag)
{

//if the multiset is empty, or if the multiset is not empty and the next departure time is greater
//than next arrival time, set simulation clock equal to next arrvial time
if(flag == false || (flag == true && (e.next_arr < e.next_dept)))

	return e.next_arr;

//otherwise multiset is not empty and next departure time is less than next arrival time, so set
//simulation clock equal to next departure time
else 

	return e.next_dept;
 	
}

//****************************************************************************************
// FUNCTION: update_fin_stat()
// ARGUMENTS: stat &s, cust &c
// RETURNS: void
// NOTES: called when a customer departs from store.  The passed in stat struct's data members
// are updated with respect to departing customer, and if there have been a multiple of 500 departures
// print desired statistics.
//****************************************************************************************

void update_fin_stat(stat &s, const cust &c)
{

//add the customer's instore-time to the running total of total shopping time
s.tot_shop +=(c.dtime - c.atime);
//indicate a new departure
s.num_dept++;
//check if this particular customer's instore-time is the smallest or largest of all before it
//if so, update min_shop or max_shop accordingly
if(s.min_shop > (c.dtime - c.atime))
	
	s.min_shop = (c.dtime - c.atime);

if(s.max_shop < (c.dtime - c.atime))

	s.max_shop = (c.dtime - c.atime);

//if this is departure number a multiple of SAMPLE_INT, print desired stats
if(s.num_dept % SAMPLE_INT == 0)

	{

	cout << "num_dept = " << setw(5) << s.num_dept << "  cust_id = " << setw(5) <<  c.id << "  arr_time = " 
	<< setw(5) << c.atime << "  dept_time = " << setw(5) << c.dtime << "  shop_time = " << setw(2) << (c.dtime-c.atime) << endl;

	}

}

//***********************************************************************************
// FUNCTION:  print_fin_stat()
// ARGUMENTS: stat &s
// RETURNS: void
// NOTES: Prints the desired statistics stored within s's stat struct  datamembers 
//
//***********************************************************************************

void print_fin_stat(stat &s)
{

cout << endl << "total num of departures = " << s.num_dept;
cout << endl << "total simulation time   = " << SIM_TIME << endl;
cout << endl << "minimum shopping time   = " << s.min_shop;
cout << endl << "maximum shopping time   = " << s.max_shop;
cout << endl << "average shopping time   = " << fixed <<  setprecision(2) 
     << (double)(s.tot_shop/s.num_dept) << endl;
}

//***********************************************************************************
// FUNCTION:  cmp::operator()
// ARGUMENTS: const cust &c1, const cust &c2
// RETURNS: bool
// NOTES:  Is the function overloader for the cmp class, which the multiset uses as a key 
// to order the set with respect the cust object's dtime data member in ascending order.
//***********************************************************************************

bool cmp::operator()(const cust &c1, const cust &c2) const
{

return c1.dtime < c2.dtime;

}

//************************************************************************************
// FUNCTION: rnd()
// ARGUMENTS: const int &low, const int &high
// RETURNS: int
// NOTES: is called when a random number needs to be generated between low and high. 
// 
//************************************************************************************

int rnd(const int &low, const int &high)
{

return (rand()%(high - low + 1) + low);

}
