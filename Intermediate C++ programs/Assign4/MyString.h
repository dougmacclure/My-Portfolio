//**************************************************************
// FILE:	MyString.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	10/18/12
//
// PURPOSE: Declares the class MyString, along with MyString friend functions/
//**************************************************************


#ifndef MYSTRING_H
#define MYSTRING_H
#include <ostream>

//need to declare namespace std since we are using ostream 

using namespace std;

class MyString
{

//friend function prototypes declared in class definition before all class members
friend ostream & operator<<(ostream&, const MyString&);
friend bool operator==(const char*, const MyString&);
//now private class members begin
char array[81];
int arSize;
static const int capacity = 80;

public:
MyString();
MyString(const char*);
bool operator==(const MyString&) const;
bool operator==(const char*) const;
char operator[](int) const;
char& operator[](int);
const char* c_str() const;
bool empty() const;
int size() const;
void clear();

};

#endif

