//**************************************************************
// FILE:	MyString.cpp
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	10/18/12
//
// PURPOSE: Class definitions for MyString class, and friend function definitions
//**************************************************************/

#include "MyString.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

/****************************************************************

FUNCTION: MyString::MyString

ARGUMENTS: None.

RETURNS: None.

NOTES: Is the default constructor.

****************************************************************/

MyString::MyString()
{

array[0] = '\0';
arSize = 0;


}

/****************************************************************

FUNCTION: MyString::MyString

ARGUMENTS: None.

RETURNS: None.

NOTES: The secondardy constructor.

****************************************************************/

MyString::MyString(const char* s)
{

if(strlen(s) <= capacity)

	{
	
	strcpy(array, s);
	arSize = strlen(s);

	}

else
	
	{
	
	strncpy(array, s, capacity);
	arSize = capacity;
	}

}


/****************************************************************

FUNCTION: MyString::operator==

ARGUMENTS: const MyString& rightOp

RETURNS: bool

NOTES: Overloads the equality operator for the MyString class

****************************************************************/

bool MyString::operator==(const MyString& rightOp) const

{

bool result = true;

for(int i = 0; array[i] != '\0'; i++)
	
	{
	
	if( array[i] != rightOp.array[i])
	
		{
		
		result = false;
		
		}
      
        }
return result;

}

/****************************************************************

FUNCTION: MyString::operator==

ARGUMENTS: const char* rightOp

RETURNS: bool

NOTES: Overloads the equality operator for the MyString class

****************************************************************/

bool MyString::operator==(const char* rightOp) const
{

bool result = true;

for(int i = 0; array[i] != '\0'; i++)
	
	{
	
	if( array[i] != rightOp[i])
	
		{
		
		result = false;
		
		}

	}

return result;

}

/****************************************************************

FUNCTION: MyString::operator[]

ARGUMENTS: int sub

RETURNS: char array[sub]

NOTES: Overloads the subscript read operator for the MyString class.
So, the subscript sub of array[] is returned.

****************************************************************/

char MyString::operator[](int sub) const

{

return array[sub];

}

/****************************************************************

FUNCTION: MyString::operator[]

ARGUMENTS: int sub

RETURNS: char& array[sub]

NOTES: Overloads the subscript write operator for the MyString class.
So, the char at position sub is returned.

****************************************************************/

char& MyString::operator[](int sub)

{

return array[sub];

}

/****************************************************************

FUNCTION: MyString::c_str

ARGUMENTS: None

RETURNS: const char* array

NOTES: Returns the name of the array, that is then converted to a 
pointer that points to the first element of the array

****************************************************************/

const char* MyString::c_str() const

{

return array;

}

/****************************************************************

FUNCTION: MyString::empty

ARGUMENTS: None

RETURNS: bool 

NOTES: Returns false if string is not empty, true if it is.

****************************************************************/

bool MyString::empty() const

{

return arSize == 0;

}

/****************************************************************

FUNCTION: MyString::size

ARGUMENTS: None

RETURNS: int size

NOTES: strlen() for strings

****************************************************************/

int MyString::size() const

{

return arSize;

}


/****************************************************************

FUNCTION: MyString::clear

ARGUMENTS: None

RETURNS: None

NOTES: makes array a null string

****************************************************************/

void MyString::clear()

{

array[0] = '\0';
arSize = 0;

}


/****************************************************************

FUNCTION: operator<<

ARGUMENTS: ostream& leftOp, const MyString& rightOp

RETURNS: ostream& leftOp

NOTES: Prints rightOp using stream object output

****************************************************************/

ostream & operator<<(ostream &leftOp, const MyString &rightOp)

{

leftOp << rightOp.array;
return leftOp;

}

/****************************************************************

FUNCTION: operator==

ARGUMENTS: const char* leftOp, const MyString& rightOp

RETURNS: bool result

NOTES: Nonmember function for the equality operator for the MyString class

****************************************************************/

bool operator==(const char* leftOp, const MyString& rightOp)

{

bool result = true;

for(int i = 0; rightOp.array[i] != '\0'; i++)

	{
	
	if( leftOp[i] != rightOp.array[i])
	
		result = false;
	
	}
return result; 

}



