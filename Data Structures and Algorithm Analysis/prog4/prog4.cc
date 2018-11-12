//*****************************************************************
// Name: Doug MacClure
// Assignment 4
// Due: 2/18/13
// File: This file defines the subroutines used in this program, 
// including main().  This program reads input until NUL is reached
// and stores it within a single string.  Then, we sift through the
// long string, to isolate individual words with respect to whitespace,
// and clean them of any non-alphanumeric characters.  Next, with each
// cleaned word, we insert all of them into a map<string,int>.  Finally
// we print the contents of the map, and other desired information.
//*****************************************************************

#include "/home/onyuksel/courses/340/common/340.h"
#include "prog4.h"
#include <ctype.h>

using namespace std;

const int NO_ITEMS = 3;
typedef string::iterator SI;
typedef string::const_iterator SCI;
typedef pair<string, int> P;


int main()
{

//create an empty map
map<string, int> m;

//call get_words to read input and build the map m
get_words(m);
cout << endl << endl;

//print the results
print_words(m);

return 0;
}


//******************************************************************
// FUNCTION: get_words()
// ARGUMENTS: map<string, int> &wmap
// RETURNS: void
// NOTES: This function is used to read input and build the passed-in
// map from the input.  
//******************************************************************

void get_words(map<string, int> &wmap)
{

//contains all input up to \0
string s;
//contains a temprorary isolated word 
string word;
//contains the cleaned version of the temporary isolated word
string cleaned;

//string iterators that are used to loop through the input string
SI i = s.begin();
SI j = s.begin();

//while we can read input with the getline() function (until NULL is reached)
while (getline(cin, s, '\0'))
	{

	//start each iterator at the beginning
	i = s.begin();
	j = s.begin();

	//while i is not pointing to the end of the input string
	while (i != s.end())
		{

		//set i equal to the first instance of whitespace in the
		//input string in the range of the initial i position to the end
		i = find_if(i, s.end(), spacecheck);
		
		//copy from the j-th postion of the input string to the i-th position
		//into the temporary word string
		copy(j, i, back_inserter(word));
			
		//call clean_entry to fill the cleaned word string 
		clean_entry(word, cleaned);
		
		//if the cleaned word string is not empty, place it into our map
		if(cleaned.size() > 0)
			wmap[cleaned]++;
		
		//resize our temprary word string back to null
		word.resize(0);
		
		//set the iterator j to i and increment i so we can move onto next word
		j = i;
		i++;
		}

	}

}


//************************************************************************
// FUNCTION: clean_entry()
// ARGUMENTS: const string &word, string &cleaned
// RETURNS: void
// NOTES: This function searches through the first instance of an alphanumeric
// character, then the next non alphanumeric character, and passes that range
// through substr() to the passed in cleaned string
//************************************************************************

void clean_entry(const string&word, string&cleaned)
{

//declare two string constant iterators for the word string and two integers indicating
//the range of the cleaned word within the word string
SCI k = word.begin();
SCI h = word.begin();
int first, last;

//set k equal to the first instance of an alphanumeric char within word
k = find_if(word.begin(), word.end(), alnumcheck);
//set h equal to the first instance of a nonalphanum char after the k-th position
h = find_if(k, word.end(), notalnumcheck);

//"convert" k and h to int
first = k - word.begin();
last = h - word.begin();

//set cleaned equal to a substring of word in the range of k to h
cleaned = word.substr(first, last-first);

//using for_each, set cleaned to be all lowercase
for_each(cleaned.begin(), cleaned.end(), makelower);

}

//************************************************************************
// FUNCTION: makelower()
// ARGUMENTS: char &x
// RETURNS: void
// NOTES: converts passed in char to lower case
//************************************************************************

void  makelower(char & x)
{

x = tolower(x);

}

//************************************************************************
// FUNCTION: alnumcheck()
// ARGUMENTS: const char &x
// RETURNS: bool
// NOTES: checks if passed in char is alphanumeric
//************************************************************************


bool alnumcheck(const char & x)
{

return isalnum(x);

}

//************************************************************************
// FUNCTION: notoalnumcheck()
// ARGUMENTS: const char &x
// RETURNS: bool
// NOTES: checks if passed in char is not alphanumeric
//************************************************************************


bool notalnumcheck(const char &x)
{

return !isalnum(x);

}

//************************************************************************
// FUNCTION: spacecheck()
// ARGUMENTS: const char &x
// RETURNS: void
// NOTES: checks if passed in char is whitespace
//************************************************************************


bool spacecheck(const char &x)
{

return isspace(x);

}

//************************************************************************
// FUNCTION: print_words()
// ARGUMENTS: const map<string, int>&wmap
// RETURNS: void
// NOTES: Creates an object for PRN class where sz isequal to wmap's size
// then sets the data members ofthe object equal to the result of
// the for_each function when going through the map and calling the function
// object overloader for the same object, which prints the map.  Then 
// the desired statistics are displayed by calling the print() member function.
//************************************************************************


void print_words(const map <string, int> &wmap)
{

PRN p(wmap.size());
p = for_each(wmap.begin(), wmap.end(),p);
p.print();

}

//************************************************************************
// FUNCTION: operator()
// ARGUMENTS: const P& p)
// RETURNS: void
// NOTES: Prints the information contained in the map, conforming to desired
// output.
//************************************************************************


void PRN::operator()(const P& p )
	{
	//print the pair's elements and increment cnt to keep track of how many times
	//we have printed
	cout << setw(16) << left << p.first << ": " << left << p.second << '\t';
	cnt++;
	//add the second element of the pair to the data member total
	total+=p.second;
	//if we have printed three elements, or are at the end of the map, print a newline
	if(cnt % NO_ITEMS == 0 || cnt == sz)
		cout << endl;

	}

//************************************************************************
// FUNCTION: print() const
// ARGUMENTS: 
// RETURNS: void
// NOTES: prints the desired statistics
//************************************************************************


void PRN::print() const 
	{

	cout << endl << "no of words in input stream: " << total;
	cout << endl << "no of words in output stream: " << sz << endl;

	}




