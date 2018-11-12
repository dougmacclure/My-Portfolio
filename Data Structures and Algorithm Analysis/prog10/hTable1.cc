#include "/home/onyuksel/courses/340/progs/13s/p10/Entry.h"
#include "/home/onyuksel/courses/340/common/340.h"
#include "/home/onyuksel/courses/340/progs/13s/p10/hTable.h"

bool less_key(const Entry *, const Entry *);




HT::HT(const unsigned &u)
{
pTable.resize(u);
hTable.resize(u);
int j = 0;
for(vector<Entry*>::iterator i = pTable.begin(); i != pTable.end(); i++)
	*i = &hTable[j];

}

HT::~HT()
{

hTable.clear();
pTable.clear();

}

void HT::insert(const Entry &newitem)
{

int pos = 0;
int cnt = 0;
int temp;
string temp2;

vector<Entry>::iterator j = hTable.begin();

vector<Entry>::iterator k; 
for(k = hTable.begin(); k != hTable.end(); k++)
	
	{
	//cout << "checking for " << newitem.key << " " << k->key << endl;

	if(k->key == newitem.key)

		break;
	pos++;


	}

//find_if(hTable.begin(), hTable.end(), [&](const &Entry x){ return (entryEqual(newitem, x);});

if(k == hTable.end())


	{
//	cout << newitem.key;
//	cout << " " << endl << "result: " << hash(newitem.key) % TBL_SZ;

	temp = hash(newitem.key) % (TBL_SZ);

	j = hTable.begin() + temp;
	//temp2 = j->key;

	while(cnt <TBL_SZ)
	
	{
		
		//cout << "checking for open position " << cnt;

			if(j->key == FREE)

			{
			hTable.insert(j+1, Entry(newitem.key, newitem.desc, newitem.num));
			vector<Entry*>::iterator i;
			//pTable.push_back(&hTable[temp]);
			for(i = pTable.begin(); *i != (Entry*)NULL; i++);
				
			if(*
						

				




			break;	
		
			}

		else

			{
		 	temp = (temp+5)%TBL_SZ;
			j = hTable.begin() + temp;
			//temp2 = j->key;
			}
		cnt++;


	}

	}

else

	cout << "Error.  Item already exists in inventory." << endl;


if(cnt==TBL_SZ)

	cout << "Table is full!" << endl;

}


void HT::search(const string &target)
{

bool found = false;

for(vector<Entry>::iterator i = hTable.begin(); i != hTable.end(); i++)

	{

	if(i->key == target)

		{

		cout << endl << "key: " << i->key << endl 
		<< "description: " << i->desc << endl
		<< "quantity: " << i->num << endl;
		found = true;
		break;
		
		}

	}

if(!found)

	cout << "Error: item not found in hash table." << endl;

}


void HT::hTable_print()
{
string temp;
int sub = 0;

for(vector<Entry>::iterator i = hTable.begin(); i != hTable.end(); i++)

	{

			
		temp = i->key;
		if(temp != FREE)

		{
		sub++;
		cout << "Item #" << sub << ": " << endl
		<< "key: " << i->key << endl
		<< "description: " << i->desc << endl
		<< "quantity: " << i->num << endl << endl;

		}	

	}

}


void HT::pTable_print()
{


for(vector<Entry*>::iterator i = pTable.begin(); i != pTable.end(); i++)

        {

                cout << "key: " << (*i)->key << endl
                << "description: " << (*i)->desc << endl
                << "quantity: " << (*i)->num << endl;



        }


sort(pTable.begin(), pTable.end(), less_key);

for(vector<Entry*>::iterator i = pTable.begin(); i != pTable.end(); i++)

	{

		cout << "key: " << (*i)->key << endl
		<< "description: " << (*i)->desc << endl
		<< "quantity: " << (*i)->num << endl;
			
		

	}

}

bool less_key(const Entry *x, const Entry *y)
{

return x->key < y->key;

}
