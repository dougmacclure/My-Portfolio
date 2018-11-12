#include "/home/onyuksel/courses/340/progs/13s/p10/Entry.h"
#include "/home/onyuksel/courses/340/common/340.h"

void HT::insert(const Entry&);
void HT::search(const string&);
void HT::hTable_print();
void HT::pTable_print();

HT::HT(const unsigned &u)
{

vector<Entry> hTable(u) = {(Entry)NULL};
vector<Entry*> pTable(u) = {(Entry*)NULL};
}


void HT::insert(const Entry &newitem)
{

int cnt = 0;
int temp;

vector<Entry>::iterator k = find_if(hTable.begin(), hTable.end(),[&](const &Entry x) { newitem.key == x.key;});

if(k == hTable.end())

	while(cnt <=TBL_SZ)
	
	{
		
		temp = hash(newitem.key);


		if(hTable[temp]==0)

			{
			hTable[temp] = newitem;
			cout << "Item entered into hTable at position " << temp << endl;
			pTable.push_back(&hTable[temp]);

			}

		else

			temp+=5;

		cnt++;


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

for(vector<Entry>::iterator i = hTable.begin(); i != hTable.end(); i++)

	{

	if(*i != (Entry)NULL)

		{

		cout << "Item #" << i << ": " << endl
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

		if(*i != (Entry*)NULL)

			{

			cout << "key: " << (*i)->key << endl
			<< "description: " << (*i)->desc << endl
			<< "quantity: " << (*i)->num << endl;
			
			}


	}

}

