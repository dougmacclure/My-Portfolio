//**************************************************************
// FILE:	Deque.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	11/28/12
//
// PURPOSE: Header file for the class definitions for the 
// Deque class
//**************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;
using std::out_of_range;


template <class T>

struct Node
{

T data;
Node<T> *next;
Node<T> *prev;
Node(const T&);

};

template <class T>

Node<T>::Node(const T &dataVal)
{

data = dataVal;
next = NULL;
prev = NULL;

}


//forward declaration of class Deque
template <class T>

class Deque;


//forward declaration of operator<<
template <class T>

ostream& operator<<(ostream&, const Deque<T>&);


template <class T>

class Deque
{
private:
friend ostream& operator<< <>(ostream&, const Deque<T>&);
Node<T> *head, *tail;
int DequeSize;

public:
Deque();
~Deque();
Deque(const Deque<T>&);
Deque<T>& operator=(const Deque<T>&);
void clear();
int size() const;
bool empty() const;
const T& front()const;
T& front();
const T& back()const;
T& back();
void push_back(const T&);
void push_front(const T&);
void pop_front();
void pop_back();
};


/****************************************************************

FUNCTION: Deque()

ARGUMENTS: none

RETURNS: nothing

NOTES: the default constructor for the Deque template class

****************************************************************/

template <class T>

Deque<T>::Deque()
{

head = NULL;
tail = NULL;
DequeSize = 0;

}

/****************************************************************

FUNCTION: ~Deque()

ARGUMENTS: none

RETURNS: nothing

NOTES: the destructor for the Deque template class. Calls the clear()
method to delete the current instance of the Deque

****************************************************************/


template <class T>

Deque<T>::~Deque()
{

clear();

}


/****************************************************************

FUNCTION: Deque()

ARGUMENTS: const Deque<T> &s

RETURNS: nothing

NOTES: the copy constructor for the Deque template class

****************************************************************/

template <class T>

Deque<T>::Deque(const Deque<T> &s)

{

//make sure head and tail pointers for new deque object are NULL
head = NULL;
tail = NULL;

//create node pointer for current instance of class to point at head ptr for the passed
//in object
Node<T> *temp = s.head;


//move through the passed in object's list with temp from head pointer to tail pointer
//stopping when temp pointer's node is NULL
while(temp != NULL)

	{
	
	push_back(temp->data);
	temp = temp->next;
	
	}

DequeSize = s.DequeSize;

}


/****************************************************************

FUNCTION: operator=()

ARGUMENTS: const Deque<T> &right

RETURNS: *this (a reference to a Deque<T> object)

NOTES: overloads the assignment operator for the Deque template class.

****************************************************************/

template<class T>


Deque<T>& Deque<T>::operator=(const Deque<T> &right)

{

//check for self assignment
if (this != &right) 

	{
	
	//make sure current instance of Deque is an empty list
	clear();
	//allocate new node & copy right Deque to current instance
	
	head = NULL;
	tail = NULL;
	Node<T> *temp = right.head;

	//go through right's list with the temp pointer, starting
	//from right's head node and moving towards the rear until
	//temp points to an empty node
	while(temp != NULL)

		{
	
		push_back(temp->data);
		temp = temp->next;
	
		}
	
	}

//return the current instance
return *this;

} 


/****************************************************************

FUNCTION: push_back()

ARGUMENTS:  const T &insertVal

RETURNS: void

NOTES: adds an extra node to the rear of the Deque, and then inserts
insertVal at the rear node.

****************************************************************/

template<class T>

void Deque<T>::push_back(const T &insertVal)

{

//need to allocate a new node that corresponds with the passed in value
Node<T>* newNode;
newNode  = new Node<T>(insertVal);
//have the node to the rear of newNode point at the head node
newNode ->prev = tail;
	
	// if we have an empty list, then head and tail both point at newNode
	
	if(tail == NULL)
	
	head = newNode;
	
	//otherwise, the node to the front of the head pointer is equal to newNode
	
	else
	
	tail->next = newNode;
	
//and the tail node is equal to newNode
	
tail = newNode;
	
//increment DequeSize
DequeSize++;

}

/****************************************************************

FUNCTION: push_front()

ARGUMENTS:  const T &insertVal

RETURNS: void

NOTES: adds an extra node to the front of the Deque, and then inserts
insertVal at the front node.

****************************************************************/

template<class T>

void Deque<T>::push_front(const T &insertVal)

{

//allocate new memory for a node, and have it store the passed in value

Node<T>* newNode;
newNode  = new Node<T>(insertVal);

//have the node to the rear of newNode point at the head node
newNode ->next = head;
	
	// if we have an empty list, then head and tail both point at newNode
	if(head == NULL)
	
	tail = newNode;
	
	//otherwise, the node to the front of the head pointer is equal to newNode
	
	else
	
	head->prev = newNode;
	
//and the head node is equal to newNode
head = newNode;
	
//increment DequeSize
DequeSize++;

}


/****************************************************************

FUNCTION: pop_back()

ARGUMENTS: none

RETURNS: void

NOTES: removes node from rear of Deque

****************************************************************/


template <class T>

void Deque<T>::pop_back()

{

//create a temporary pointer that points to what is stored at the tail ptr, then
//move tail pointer to the previous node
	
Node<T> *delNode = tail;
tail = delNode->prev;

//if tail node is now NULL, then our list only had one node to begin with

if(tail == NULL)

	head = NULL;

//otherwise signify that the node next to tail ptr is NULL and delete the info stored within it	  
	
else
	
	tail->next = NULL;
	
delete delNode;	   

DequeSize--;
	
}


/****************************************************************

FUNCTION: pop_front()

ARGUMENTS: none

RETURNS: void

NOTES: removes node from front of Deque

****************************************************************/


template <class T>

void Deque<T>::pop_front()

{

//create a temporary pointer that points to what is stored at the head ptr, then
//move head pointer to the node next to it	  
Node<T> *delNode = head;
head = delNode->next;

//if head node is now NULL, then our list only had one node to begin with
if(head == NULL)

	tail = NULL;

//otherwise signify that the node previous of head ptr is NULL and delete the info stored within it	   
else
	
	head->prev = NULL;
	
delete delNode;	   
	
DequeSize--;

}




/****************************************************************

FUNCTION: clear()

ARGUMENTS: none

RETURNS: void

NOTES: clears the linked list for a Deque template class object

****************************************************************/

template <class T>

void Deque<T>::clear()
{

//check if head is NULL
if(head == 0)

	{
	
	tail = NULL;
	head = NULL;
	DequeSize = 0;
	}
	
	
else

	{
	//create a tenporary pointer that we use to go through the linked list starting
	//at the front of the list

	Node<T> *temp1;
	temp1 = head;
	
	//use a while loop to go through the list, and ends when it reaches the end
	//or where the tenp pointer has reached a NULL node
	while (temp1!=NULL)
	
		{
		//move the head pointer forward
		head = head->next;
		//delete what is stored at the node temp1 points at
		delete temp1;
		//move temp1 one step forward
		temp1 = head->next;
	
		}
	//signify that we now have an empty Deque
	tail = NULL;
	head = NULL;
	DequeSize = 0;
	
	}
	
	
	

}


/****************************************************************

FUNCTION: size()

ARGUMENTS: none

RETURNS: int DequeSize

NOTES: get method for Deque template class

****************************************************************/

template<class T>

int Deque<T>::size() const

{

return DequeSize;

}


/****************************************************************

FUNCTION: empty()

ARGUMENTS: none

RETURNS: bool (empty)

NOTES: checks if head & tail are both NULL, i.e., the Deque is empty

****************************************************************/

template<class T>

bool Deque<T>::empty() const

{

return head == NULL && tail == NULL;

}


/****************************************************************

FUNCTION: operator<<()

ARGUMENTS: ostream &out,const Deque<T> &right

RETURNS: ostream &out

NOTES: the output assignment operator for the Deque template class

****************************************************************/

template <class T>

ostream& operator<<(ostream &out, const Deque<T>& right)

{

//create a temp node pointer that we use to go through the linked list starting
//from front of list
Node<T> *temp;
temp = right.head;

//check if we have an empty Deque
if(temp == NULL)
	
	out << "Deque is empty";
	
else

	{
	//use a while loop to go through list, and end when temp is NULL
	while(temp != NULL)
	
		{
		
		//print out what is held in each node
		out << temp->data << " ";
		temp = temp->next;
		
		}
	
	}

//return what we want to print
return out;

}


/****************************************************************

FUNCTION: front()

ARGUMENTS: none

RETURNS: T& head->data

NOTES: returns the data stored at the beginning of the list

****************************************************************/

template <class T>

T& Deque<T>::front()

{

return head->data;
	

}

/****************************************************************

FUNCTION: front()

ARGUMENTS: none

RETURNS: const T& head->data

NOTES: returns the data stored at the beginning of the list

****************************************************************/

template <class T>

const T& Deque<T>::front() const

{

return head->data;
	

}



/****************************************************************

FUNCTION: back()

ARGUMENTS: none

RETURNS: T& "tail->data"

NOTES: returns the data stored at the end of the Deque

****************************************************************/
template <class T>

T& Deque<T>::back() 

{



	
//create temp1 pointer to node to go through linked list starting from front
Node<T> *temp1 = head;
//use while loop to loop through linked list, and stop when node next to
//temp1 is NULL
while (temp1 -> next != NULL)
		
	{
		
	//move temp1 one step back to end of list
	temp1 = temp1->next;
	
	}
//return what is stored in the last node of the Deque
return temp1->data;
	

}

/****************************************************************

FUNCTION: back()

ARGUMENTS: none

RETURNS: const T& "tail->data"

NOTES: returns the data stored at the end of the Deque

****************************************************************/
template <class T>

const T& Deque<T>::back() const

{

Node<T> *temp1 = head;
//use while loop to loop through linked list, and stop when node next to
//temp1 is NULL
while (temp1 -> next != NULL)
	
	{
	
	//move temp1 one step back to end of list
	temp1 = temp1->next;
	
	}
 //return what is stored in the last node of the Deque
return temp1->data;
	
}


#endif


