
//Doug MacClure
//CSCI 330 - 3
//Asssignment 10
//Due: 4/24/13

#include "/home/onyuksel/courses/340/progs/13s/p10/Entry.h"
#include "/home/onyuksel/courses/340/common/340.h"
#include "/home/onyuksel/courses/340/progs/13s/p10/hTable.h"

//function prototype
bool less_key(const Entry *, const Entry *);



//********************************************************************************
// FUNCTION:  HT()
// ARGUMENTS: const unsigned &u
// RETURNS: void
// NOTES: constructor for HT class
//
//********************************************************************************
HT::HT(const unsigned &u)
{
pTable.resize(0);
hTable.resize(u);

}

//********************************************************************************
// FUNCTION: ~HT()
// ARGUMENTS: void
// RETURNS: void
// NOTES: desctructor for HT class
//
//********************************************************************************


HT::~HT()
{

hTable.clear();
pTable.clear();

}

//********************************************************************************
// FUNCTION:   insert()
// ARGUMENTS: const Entry &newitem
// RETURNS: void
// NOTES:  Insert function.  Using passed in object's key data member, checks if key already 
// exists in table.  If so, print message signifying entry already exists.  If not, prepare to 
// enter value.  Using linear probing to avoid clusters, cycle through table to find empty spot
// If table is full, print error message and exit.
//********************************************************************************


void HT::insert(const Entry &newitem)
{

//index variables 
int pos = 0;
int cnt = 0;
int temp;


string temp2;

vector<Entry>::iterator j = hTable.begin();

vector<Entry>::iterator k; 

//check if key already exists in table
for(k = hTable.begin(); k != hTable.end(); k++)
	
	{

	//if we found a match, exit for loop
	if(k->key == newitem.key)

		break;
	pos++;


	}


//if for loop didn't cycle through hTable, then search for open position in table
if(k == hTable.end())


	{

	//call hash function to determine index of table we want to start search
	temp = hash(newitem.key) % (TBL_SZ);

	j = hTable.begin() + temp;

	//while we haven't checked every position in table

	while(cnt <TBL_SZ)
	
	{
		
			//if we found an open slot dictated by linear probing
			if(j->key == FREE)

			{
			//put passed-in class object into table at position pointed to by iterator j
			*j = Entry(newitem.key, newitem.desc, newitem.num);
			//add the address of newly inserted object in hTable into pointer table
			pTable.push_back(&hTable[temp]);
			//indicate where in table we have inserted object	
			cout << " entry = " << temp << endl;				
			//exit loop
			break;	
		
			}

			//otherwise the position we are checking is occupied
			else

			{
			//jump ahead 5 spaces (5 is relatively prime to 31, so this is okay and avoids primary clustering)
		 	temp = (temp+5)%TBL_SZ;
			j = hTable.begin() + temp;
			}
		cnt++;


	}

	}

//otherwise we found a duplicate key in table
else

	cout << "not inserted - duplicate key!!!" << endl;

//if we have checked every spot in table and all occupied, print error message
if(cnt==TBL_SZ)

	cout << "Table is full!" << endl;

}


//********************************************************************************
// FUNCTION:  search()
// ARGUMENTS: const string &target
// RETURNS: void
// NOTES: loops through hTable, if it finds a matching key, it prints desired info.  Otherwise
// if no match is found it prints an error message.
//********************************************************************************


void HT::search(const string &target)
{

//used to determine if match is found
bool found = false;

//loop through hTable 
for(vector<Entry>::iterator i = hTable.begin(); i != hTable.end(); i++)

	{

	//if the passed in key finds a match within the table of objects' key datamember, print desired info and exit loop
	if(i->key == target)

		{

		cout << " ==> number:" << right << setw(5) << i->num << " - item: " << i->desc << endl;
		//set found to true so we don't print error message
		found = true;
		break;
		
		}

	}
//if no match is found print error message
if(!found)

	cout << " not in table!!" << endl;

}


//********************************************************************************
// FUNCTION:  hTable_print()
// ARGUMENTS: void
// RETURNS: void
// NOTES: Loops through hTable which is unsorted.  Prints desired info for each element
// in hTable that we have inserted.
//********************************************************************************


void HT::hTable_print()
{
string temp;
int sub = 0;


//print all elements whose key is not "$$$"
for(vector<Entry>::iterator i = hTable.begin(); i != hTable.end(); i++)

	{

	
		temp = i->key;
		if(temp != FREE)

		{
			
		cout << setw(4)	<< sub << ":  " << i->key << "  - " << right << setw(5) << i->num
		<< "  -  " << i->desc << endl;

		}
	sub++;

	}

}

//********************************************************************************
// FUNCTION:  pTable_print()
// ARGUMENTS: void
// RETURNS: void
// NOTES: sort pTable with respect to the key of the hTable element.  Print pTable like
// above function.
//********************************************************************************


void HT::pTable_print()
{

//call sort to sort in ascending order with respect to key data member
sort(pTable.begin(), pTable.end(), less_key);

//simple for loop where we print every element of pTable

for(vector<Entry*>::iterator i = pTable.begin(); i != pTable.end(); i++)

	{

	cout << " " << setw(5) << (*i)->key << "  - " << right << setw(5) << (*i)->num << "  -  "
		<< (*i)->desc << endl;
			
		

	}

}


//********************************************************************************
// FUNCTION: less_key() 
// ARGUMENTS: const Entry *x, *y
// RETURNS: bool
// NOTES: predicate function we use with sort() STL function.  Return whether or not the
// left argument's key value is less than the right argument's key value
//********************************************************************************


bool less_key(const Entry *x, const Entry *y)
{

return x->key < y->key;

}
