//**************************************************************
// FILE:	MyString.cpp
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	10/25/12
//
// PURPOSE: Class definitions for MyString class, and friend function definitions
// now with dynamic memory allocation and added classes and data members.
//**************************************************************/

#include "MyString.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <stdexcept>

using std::out_of_range;
using namespace std;

/****************************************************************

FUNCTION: MyString::MyString

ARGUMENTS: None.

RETURNS: None.

NOTES: Is the default constructor.

****************************************************************/

MyString::MyString()
{

arSize = 0;
strCapacity = 1;
stringArPtr = new char[strCapacity];
stringArPtr[0] = 0;

}

/****************************************************************

FUNCTION: MyString::MyString

ARGUMENTS: None.

RETURNS: None.

NOTES: The secondardy constructor.

****************************************************************/

MyString::MyString(const char* s)
{

arSize = strlen(s);
strCapacity = arSize + 1;
stringArPtr = new char[strCapacity];
strcpy(stringArPtr, s);

for(int i = 0; i < strCapacity; i++)

	stringArPtr[i] = s[i];

}


/****************************************************************

FUNCTION: MyString::MyString

ARGUMENTS: const Mystring& s

RETURNS: None.

NOTES: The copy constructor.

****************************************************************/

MyString::MyString(const MyString& s)
{

arSize = s.arSize;
strCapacity = s.strCapacity;

//make a copy of s, instead of another address that points to s
stringArPtr = new char[strCapacity];

for(int i = 0; i < strCapacity; i++)

	stringArPtr[i] = s.stringArPtr[i];


}


/****************************************************************

FUNCTION: MyString::~MyString

ARGUMENTS: None.

RETURNS: None.

NOTES: The destructor.

****************************************************************/

MyString::~MyString()
{

//frees up dynamic memory
delete [] stringArPtr;

}

/****************************************************************

FUNCTION: MyString::capacity

ARGUMENTS: None.

RETURNS: int strCapacity

NOTES: Simple get method.

****************************************************************/

int MyString::capacity() const
{

return strCapacity;

}

/****************************************************************

FUNCTION: MyString::operator=

ARGUMENTS: const MyString& rightOp

RETURNS: const MyString& *this

NOTES: Overloads the assignment operator, where one MyString object (rightOb)
is assigned to another (*this/whatever object is on the LHS of the operation)

****************************************************************/

const MyString& MyString::operator=(const MyString& rightOp)
{

//1) Check for self-assignment, where "this" points to the object on the LHS

if(this != &rightOp)

	{
	//1.5) assign non-array data members to the object on the LHS
	strCapacity = rightOp.strCapacity;
	arSize = rightOp.arSize;
	
	//2) delete dynamic memory associated with the stringArPtr pointer
	delete [] stringArPtr;
	
	//3) grab new chunk of dynamic memory for a char array associated with the stringArPtr
	stringArPtr = new char[strCapacity];
	
	//4) copy info
	
	for(int i = 0; i < strCapacity; i++)
	
		{
		
		stringArPtr[i] = rightOp.stringArPtr[i];
		
		}
	//5) return what is on the left of the assignment operation in main()
	return *this;
	
	}

//do nothing if we have self-assignment
return *this;

}

/****************************************************************

FUNCTION: MyString::operator=

ARGUMENTS: const MyString& rightOp

RETURNS: const MyString& *this

NOTES: Overloads the assignment operator for the MyString class, for the case where
we are assigning a C string to a MyString object.  In other words, we have a MyString
object on the LHS and a C-string on the RHS of the operation.

****************************************************************/

const MyString& MyString::operator=(const char* rightOp)

{

arSize = strlen(rightOp);

//check to make sure that the capacity for the array has room for the 
//null terminator, at least.  If there is not room for the null terminator
//resize the string array so that the max capacity is arSize + 1
if(strCapacity < arSize + 1)
	
	{
	
	delete [] stringArPtr;
	strCapacity = arSize + 1;
	stringArPtr = new char[strCapacity];
		
	}

//copy the C-String into the MyString object on the LHS of the operation
for( int i = 0; i < strCapacity; i++)

	{
	
	stringArPtr[i] = rightOp[i];
	
	}

//return the MyString object on the LHS of the operation
return *this;

}


/****************************************************************

FUNCTION: MyString::operator+

ARGUMENTS: const MyString& rightOp

RETURNS: MyString newObj

NOTES: Overloads the addition operator for the MyString class

****************************************************************/

MyString MyString::operator+(const MyString& rightOp) const
{

//create a new object
MyString newObj;

//make sure that the string size of the new object is big enough to fit
//the two arrays on both sides of the operation
newObj.arSize = arSize + rightOp.arSize;

//delete the new object's string array to free up dynamic memory associated with it
delete [] newObj.stringArPtr;

//make sure that there is room for the null terminator in the new object's array
newObj.strCapacity = newObj.arSize + 1;

//allocate a new array of char asociated with the array for new object, so that 
//the size of the array is equal to the new object's string capacity
newObj.stringArPtr = new char[newObj.strCapacity];

//first copy into the new object's array, the string that is on the LHS of the 
//operation, so we have a proper concatenation
strcpy(newObj.stringArPtr, stringArPtr);

//concatenate what is on the RHS into the new object's array
strcat(newObj.stringArPtr, rightOp.stringArPtr);

//return the new object we made
return newObj;

}


/****************************************************************

FUNCTION: MyString::operator+

ARGUMENTS: const char* rightOp

RETURNS: MyString newObj

NOTES: Overloads the addition operator for the MyString class

****************************************************************/

MyString MyString::operator+(const char* rightOp) const
{

//basically the same pseudocode as above, except we concatenate a C-String
//into the new object's array with the LHS's string put into the new object's
//array first

MyString newObj;
newObj.arSize = arSize + strlen(rightOp);
delete [] newObj.stringArPtr;
newObj.strCapacity = newObj.arSize + 1;
newObj.stringArPtr = new char[newObj.strCapacity];
strcpy(newObj.stringArPtr, stringArPtr);
strcat(newObj.stringArPtr, rightOp);
return newObj;

}



/****************************************************************

FUNCTION: MyString::at(int) const throw(out_of_range)

ARGUMENTS: int sub

RETURNS: char stringArPtr[sub]

NOTES: Returns the element of the array object at element sub for the MyString class.

****************************************************************/

char MyString::at(int sub) const throw(out_of_range)

{

if ( sub < 0 or sub >= arSize)

	throw out_of_range("Subscript out of range");	

else

	return stringArPtr[sub];

}


/****************************************************************

FUNCTION: MyString::at(int sub) throw(out_of_range)

ARGUMENTS: int sub

RETURNS: char& stringArPtr[sub]

NOTES: Returns the element of the array object at element sub for the MyString class.

****************************************************************/

char& MyString::at(int sub) throw(out_of_range)

{

if ( sub < 0 or sub >= arSize)

	throw out_of_range("Subscript out of range");	

else

	return stringArPtr[sub];


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

for(int i = 0; stringArPtr[i] != '\0'; i++)
	
	{
	
	if( stringArPtr[i] != rightOp.stringArPtr[i])
	
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

for(int i = 0; stringArPtr[i] != '\0'; i++)
	
	{
	
	if( stringArPtr[i] != rightOp[i])
	
		{
		
		result = false;
		
		}

	}

return result;

}

/****************************************************************

FUNCTION: MyString::operator[]

ARGUMENTS: int sub

RETURNS: char stringArPtr[sub]

NOTES: Overloads the subscript read operator for the MyString class.
So, the subscript sub of stringArPtr[] is returned.

****************************************************************/

char MyString::operator[](int sub) const

{

return stringArPtr[sub];

}

/****************************************************************

FUNCTION: MyString::operator[]

ARGUMENTS: int sub

RETURNS: char& stringArPtr[sub]

NOTES: Overloads the subscript write operator for the MyString class.
So, the char at position sub is returned.

****************************************************************/

char& MyString::operator[](int sub)

{

return stringArPtr[sub];

}

/****************************************************************

FUNCTION: MyString::c_str

ARGUMENTS: None

RETURNS: const char* stringArPtr

NOTES: Returns the name of the stringArPtr, that is then converted to a 
pointer that points to the first element of the stringArPtr

****************************************************************/

const char* MyString::c_str() const

{

return stringArPtr;

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

NOTES: makes stringArPtr a null string

****************************************************************/

void MyString::clear()

{

stringArPtr[0] = '\0';
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

leftOp << rightOp.stringArPtr;
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

for(int i = 0; rightOp.stringArPtr[i] != '\0'; i++)

	{
	
	if( leftOp[i] != rightOp.stringArPtr[i])
	
		result = false;

	}
return result; 

}

/****************************************************************

FUNCTION: operator+

ARGUMENTS: const char* leftOp, const MyString& rightOp

RETURNS: Mystring newObj

NOTES: Nonmember function for the addition operator for the MyString class

****************************************************************/

MyString operator+(const char* leftOp, const MyString& rightOp)

{

//create a new object, called the result object that is the result of the operation
MyString newObj;
newObj.arSize = strlen(leftOp) + rightOp.arSize;

//free up dynamic memory associated with the result object's array
delete [] newObj.stringArPtr;

//we can now redefine the size of the result object's array to be large enough to fit in
//what is in the strings on RHS and LHS of operation, plus the null terminator
newObj.strCapacity = newObj.arSize + 1;

//allocate a new array of char with the pointer to char that is of the redefined size
newObj.stringArPtr = new char[newObj.strCapacity];

//first copy in what is in the C-String on the LHS to the result object's array
strcpy(newObj.stringArPtr, leftOp);

//concatenate the string associated with the RHS into the result object's array
strcat(newObj.stringArPtr, rightOp.stringArPtr);

//return the result object
return newObj;

}



void MyString::changeSize(int newCap)
{

//need temporary pointer so we don't overwrite the original pointer to a char array

char *tempPtr;
strCapacity = newCap;
tempPtr = new char[strCapacity];

for (int i = 0; i <= arSize; i++)

	tempPtr[i] = stringArPtr[i];

delete [] stringArPtr;
stringArPtr = tempPtr;
}
