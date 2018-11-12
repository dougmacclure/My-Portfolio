//*************************************************************************
// Doug MacClure
// Assignment 4
// Due: 2/18/13
// File: header file including function prototypes, and class definition
// for PRN
//*************************************************************************


#ifndef PROG4_H
#define PROG4_H
#include "/home/onyuksel/courses/340/common/340.h"

using namespace std;

typedef pair<string, int> P;

void get_words(map<string, int> &);
void print_words(const map<string, int> &);
void clean_entry(const string&, string&);
bool alnumcheck(const char&);
bool notalnumcheck(const char&);
bool spacecheck(const char&);
void makelower(char&);

//***************************************************************************
//CLASS: PRN
//
//NOTES: Used to print out the contents of a map, and the number of 
//cleaned words. 
//***************************************************************************


class PRN{

	private:
		
		//sz denotes the size of the map, cnt keeps track of our position in the map
		//and total denotes the total number of words entered from input
		int sz, cnt, total;
			
	public:
	
		//consuctor
		PRN ( const int& s = 1, const int& c = 0, const int& t = 0 ):sz(s), cnt(c), total(t){}
	 	//overloaded function operator
		void operator()(const P& p);
		//member print function
		void print() const;

};
#endif

