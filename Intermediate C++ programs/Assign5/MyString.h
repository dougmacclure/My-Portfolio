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
#include <stdexcept>
//need to declare namespace std since we are using ostream 
using std::out_of_range;
using namespace std;

class MyString
{

//friend function prototypes declared in class definition before all class members
friend MyString operator+(const char*, const MyString&);
friend ostream & operator<<(ostream&, const MyString&);
friend bool operator==(const char*, const MyString&);
//now private class members begin
char *stringArPtr;
int strCapacity;
int arSize;  //must always be <= strCapacity - 1


public:
MyString();
~MyString();

MyString(const char*);
MyString(const MyString&);
void changeSize(int);
const MyString& operator=(const MyString&);
const MyString& operator=(const char*);
MyString operator+(const MyString&) const;
MyString operator+(const char*) const;
char at(int) const throw(out_of_range);
char& at(int) throw(out_of_range);

bool operator==(const MyString&) const;
bool operator==(const char*) const;
char operator[](int) const;
char& operator[](int);
const char* c_str() const;
bool empty() const;
int capacity() const;
int size() const;
void clear();

};

#endif

