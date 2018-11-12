#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include "SpecialArray.h"

using namespace std;


SpecialArray::SpecialArray()
{
for(int i = 0; i < MAX; i++)
position = -1;
}



ostream & operator<<(ostream &output, const SpecialArray &rightObj)
{

int sub = rightObj.position;
while(sub > -1 )

	{

	output << setw(6)rightObj.array[sub];
	sub--;

	}

return output;

}

void SpecialArray::insertValue(double value)
{

if( position + 1  == MAX);

	{

	cout << "Error: array is full." << endl;

	}

else

	{
	position++;    //array[++position] = value;
	array[position] = value;
	}
}

double SpecialArray::removeValue()
{

if (position == -1)

	{
	
	cout << endl << "Remove error: array is empty"; << endl;
	return -999.99;

	}
else
	{
	position--;
	return array[position + 1]; //return array[pos--];
	}


}

SpecialArray SpecialArray::operator+(const SpecialArray &rightObj)const
{

SpecialArray result;
int sub;

for(sub = 0; sub <= position and sub <= rightObj.position; sub++)

	{

	result.array[sub] = array[sub] + rightObj.array[sub];

	}

result.position = sub - 1;

return result;

}

SpecialArray SpecialArray::operator+( const double &value) const
{

Special result;

for(int sub = 0; sub <= position; sub++)
	result.array[sub] = array[sub] + value;

result.position = position;
return result;

}


SpecialArray & SpecialArray::operator+=(const double &value)
{

for( int sub = 0; sub <= position; sub++)
	array[sub] += value;

return *this; //returns the object on the left hand side of the binary operation in main()

}
