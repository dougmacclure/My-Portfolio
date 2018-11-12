//**************************************************************
// FILE:	Stack.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	11/01/12
//
// PURPOSE: Header file for the class definition prototype for the 
// Stack class
//**************************************************************/


#ifndef STACK_H
#define STACK_H

#include <ostream>
#include <stdexcept>
using std::out_of_range;
using namespace std;

class Stack
{

private:
friend ostream& operator<<(ostream &, const Stack&);
int *stackAr, stackCap, stackSize, stackTop;
void resize(int);

public:

Stack();
~Stack();
Stack(const Stack &);
const Stack & operator=(const Stack&);
void clear();
int size() const;
int capacity() const;
bool empty() const;
int top() const throw(out_of_range);
void push(int);
void pop() throw(out_of_range);


};

#endif

