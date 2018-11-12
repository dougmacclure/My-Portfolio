//**************************************************************
// FILE:	Stack.cpp
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	11/01/12
//
// PURPOSE: Class definitions for Stack class, and friend function definitions;
// Makes use of stacks.
//**************************************************************/


#include "Stack.h"
#include <cstdio>
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <ostream>

using std::out_of_range;
using namespace std;

/****************************************************************

FUNCTION: Stack::Stack

ARGUMENTS: None.

RETURNS: None.

NOTES: Is the default constructor.

****************************************************************/

Stack::Stack()
{

stackCap = 1;
stackAr = new int[stackCap];
stackSize = 0;
stackTop = -1;

}



/****************************************************************

FUNCTION: Stack::Stack()

ARGUMENTS: const Stack& s

RETURNS: None.

NOTES: The copy constructor.

****************************************************************/

Stack::Stack(const Stack& s)
{

stackTop = s.stackTop;
stackSize = s.stackSize;
stackCap = s.stackCap;
stackAr = new int[stackCap];

for(int i = 0; i < stackSize; i++)

	stackAr[i] = s.stackAr[i];


}


/****************************************************************

FUNCTION: Stack::~Stack

ARGUMENTS: None.

RETURNS: None.

NOTES: The destructor.

****************************************************************/

Stack::~Stack()
{

delete [] stackAr;

}


/****************************************************************

FUNCTION: Stack::operator=

ARGUMENTS: const Stack& rightOp

RETURNS: const Stack& *this

NOTES: Overloads the assignment operator, where one Stack object (rightOp)
is assigned to another (*this)

****************************************************************/

const Stack& Stack::operator=(const Stack& rightOp)
{

//1) Check for self-assignment

if(this != &rightOp)

	{
	
	stackTop = rightOp.stackTop;
	stackCap = rightOp.stackCap;
	stackSize = rightOp.stackSize;
	
	//2) delete dynamic memory
	delete [] stackAr;
	
	//3) grab new chunk of dynamic memory
	stackAr = new int[stackCap];
	
	//4) copy info
	
	for(int i = 0; i < rightOp.stackCap; i++)
	
		{
		
		stackAr[i] = rightOp.stackAr[i];
		
		}
	//5) return what is on the left of the assignment operation in main()
	return *this;
	
	}

//do nothing if we have self-assignment
return *this;

}


/****************************************************************

FUNCTION: operator<<

ARGUMENTS: ostream& leftOp, const Stack& rightOp

RETURNS: ostream& leftOp

NOTES: Prints rightOp using stream object output

****************************************************************/

ostream & operator<<(ostream &leftOp, const Stack &rightOp) 

{

for(int i = 0; i < rightOp.size(); i++)
	
	leftOp << rightOp.stackAr[i] << " ";
	
return leftOp;

}


/****************************************************************

FUNCTION: Stack::clear()

ARGUMENTS: none

RETURNS: void

NOTES: sets stack back to initial size

****************************************************************/

void Stack::clear()

{

stackCap = 1;
stackSize = 0;
stackTop = -1;

}

/****************************************************************

FUNCTION: Stack::size()

ARGUMENTS: none

RETURNS: int stackSize

NOTES: get method for stackSize

****************************************************************/

int Stack::size() const
{

return stackSize;

}

/****************************************************************

FUNCTION: Stack::capacity()

ARGUMENTS: none

RETURNS: int stackCap

NOTES: get method for stackCap

****************************************************************/

int Stack::capacity() const
{

return stackCap;

}
/****************************************************************

FUNCTION: Stack::empty()

ARGUMENTS: none

RETURNS: bool result

NOTES: checks if stack is empty

****************************************************************/

bool Stack::empty() const
{

return stackSize == 0;

}

/****************************************************************

FUNCTION: Stack::top()

ARGUMENTS: none

RETURNS: int stackTop

NOTES: get method for stackTop

****************************************************************/

int Stack::top() const throw(out_of_range)
{

if(empty())

	throw out_of_range("Stack underflow on top()");

else

	return stackAr[stackTop];

}


/****************************************************************

FUNCTION: Stack::push()

ARGUMENTS: int newItem

RETURNS: void

NOTES: pushes an item into the stack

****************************************************************/

void Stack::push(int newItem)
{

if (stackSize == stackCap)

	{
	
	resize(stackCap*2);
	
	}
	
stackTop++;
stackAr[stackTop] = newItem;
stackSize++;

}

/****************************************************************

FUNCTION: Stack::pop()

ARGUMENTS: none

RETURNS: void

NOTES: pops an item out of a stack

****************************************************************/

void Stack::pop() throw(out_of_range)
{

if(empty())

	throw out_of_range("Stack underflow on pop()");
	
else

	{
	
	stackTop--;
	stackSize--;
	
	if(stackSize > 0 and stackSize == (stackCap/4))
	
		resize(stackCap/2);
	
	}

}

/****************************************************************

FUNCTION: Stack::resize()

ARGUMENTS: int newCap

RETURNS: void

NOTES: private method that resizes the stack

****************************************************************/

void Stack::resize(int newCap)
{

stackCap = newCap;
int *tempStack;
tempStack = new int[stackCap];

for(int i = 0; i < stackSize; i++)
	tempStack[i] = stackAr[i];

delete [] stackAr;
stackAr = tempStack;

}

