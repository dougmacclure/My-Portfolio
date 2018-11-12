//**************************************************************
// FILE:	Queue.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	11/20/12
//
// PURPOSE: Header file for the class definitions for the 
// Queue class
//**************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

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
Node(const T&);

};

template <class T>

Node<T>::Node(const T &dataVal)
{

data = dataVal;
next = NULL;

}


//forward declaration of class Queue
template <class T>

class Queue;


//forward declaration of operator<<
template <class T>

ostream& operator<<(ostream&, const Queue<T>&);


template <class T>

class Queue
{
private:
void copylist(const Node<T>*, Node<T>*&);
friend ostream& operator<< <>(ostream&, const Queue<T>&);
Node<T> *qFront, *qRear;
int queueSize;

public:
Queue();
~Queue();
Queue(const Queue<T>&);
Queue<T>& operator=(const Queue<T>&);
void clear();
int size() const;
bool empty() const;
T front()const throw(out_of_range);
T back()const throw(out_of_range);
void push(const T&);
void pop() throw(out_of_range);
};


/****************************************************************

FUNCTION: Queue()

ARGUMENTS: none

RETURNS: nothing

NOTES: the default constructor for the Queue template class

****************************************************************/

template <class T>

Queue<T>::Queue()
{

qFront = NULL;
qRear = NULL;
queueSize = 0;

}

/****************************************************************

FUNCTION: ~Queue()

ARGUMENTS: none

RETURNS: nothing

NOTES: the destructor for the Queue template class. Calls the clear()
method to delete the current instance of the queue

****************************************************************/


template <class T>

Queue<T>::~Queue()
{

clear();

}


/****************************************************************

FUNCTION: Queue()

ARGUMENTS: const Queue<T> &s

RETURNS: nothing

NOTES: the copy constructor for the Queue template class

****************************************************************/

template <class T>

Queue<T>::Queue(const Queue<T> &s)

{

//use copylist() to simplify this method
copylist(s.qFront, qFront);
queueSize = s.queueSize;

}


/****************************************************************

FUNCTION: operator=()

ARGUMENTS: const Queue<T> &right

RETURNS: *this (a reference to a Queue<T> object)

NOTES: overloads the assignment operator for the Queue template class.

****************************************************************/

template<class T>


Queue<T>& Queue<T>::operator=(const Queue<T> &right)

{

//check for self assignment
if (this != &right) 

	{
	
	//delete current instance of the queue
	clear();
	//allocate new node & copy right queue to current instance
	copylist(right.qFront, qFront);
		
	}

//return the current instance
return *this;

} 


/****************************************************************

FUNCTION: push()

ARGUMENTS:  const T &insertVal

RETURNS: void

NOTES: adds an extra node to the rear of the queue, and then inserts
insertVal at the rear node.

****************************************************************/

template<class T>

void Queue<T>::push(const T &insertVal)

{

//need to allocate a new node that corresponds with the passed in value
Node<T>* newNode;
newNode  = new Node<T>(insertVal);

//check if the current instance of the queue is empty
if( qFront == NULL)

	{
	
	newNode ->next = qFront;
	qFront = newNode;
	
	}
	
else

	{
	
	//create a temproary pointer that moves through the linked list starting from qFront
	Node<T> *temp1 = qFront;
	
	//use a while loop to go through the list, and stops when the next node is NULL
	while (temp1 -> next != NULL)
		
		{
		//move to the next node towards the rear of the queue
		temp1 = temp1->next;
		
		}
	//now that we are at the end of the list, clarify that the node next to newNode is empty
	newNode->next = NULL;
	//then place  newNode next to temp1
	temp1->next = newNode;
	//have qRear point to the newest node occupied by newNode at the end of the list
	qRear = newNode;
	
	}

//increment queueSize
queueSize++;

}

/****************************************************************

FUNCTION: clear()

ARGUMENTS: none

RETURNS: void

NOTES: clears the linked list for a Queue template class object

****************************************************************/

template <class T>

void Queue<T>::clear()
{

//check if qFront is NULL
if(qFront == 0)

	{
	
	qRear = NULL;
	qFront = NULL;
	queueSize = 0;
	}
	
	
else

	{
	//create a tenporary pointer that we use to go through the linked list starting
	//at the front of the list

	Node<T> *temp1;
	temp1 = qFront;
	
	//use a while loop to go through the list, and ends when it reaches the end
	//or where the tenp pointer has reached a NULL node
	while (temp1!=NULL)
	
		{
		//move the qFront pointer forward
		qFront = qFront->next;
		//delete what is stored at the node temp1 points at
		delete temp1;
		//move temp1 one step forward
		temp1 = qFront->next;
	
		}
	//signify that we now have an empty Queue
	qRear = NULL;
	qFront = NULL;
	queueSize = 0;
	
	}
	
	
	

}


/****************************************************************

FUNCTION: copylist()

ARGUMENTS: const Node<T> *existNode, Node<T> *&newNode

RETURNS: void

NOTES: using recursion, go through an existing queue and create new nodes and the data stored 
in them simultaneously for a new queue

****************************************************************/

template <class T>

void Queue<T>::copylist(const Node<T>*existNode, Node<T>* &newNode)

{

//each time this is called recursively, it will be called until
//the existNode pointer (the passed in qFront pointer) points to a NULL node
if( existNode != 0)

	{

	//allocate memory for the next node
	newNode = new Node<T>( existNode -> data);
	//call copylist recursively and pass in the pointers next to
	//existNode and newNode with the next pointer
	copylist( existNode -> next, newNode -> next);
	//we also need to update the queueSize for the assignment operator's
	//current instance of the Queue linked list
	queueSize++;

	}


}

/****************************************************************

FUNCTION: size()

ARGUMENTS: none

RETURNS: int queueSize

NOTES: get method for Queue template class

****************************************************************/

template<class T>

int Queue<T>::size() const

{

return queueSize;

}


/****************************************************************

FUNCTION: empty()

ARGUMENTS: none

RETURNS: bool (empty)

NOTES: checks if qFront & qRear are both NULL, i.e., the queue is empty

****************************************************************/

template<class T>

bool Queue<T>::empty() const

{

return qFront == NULL && qRear == NULL;

}


/****************************************************************

FUNCTION: operator<<()

ARGUMENTS: ostream &out,const Queue<T> &right

RETURNS: ostream &out

NOTES: the output assignment operator for the Queue template class

****************************************************************/

template <class T>

ostream& operator<<(ostream &out, const Queue<T>& right)

{

//create a temp node pointer that we use to go through the linked list starting
//from front of list
Node<T> *temp;
temp = right.qFront;

//check if we have an empty queue
if(temp == NULL)
	
	out << "Queue is empty";
	
else

	{
	//use a while loop to go through list, and end when temp is NULL
	while(temp != NULL)
	
		{
		
		//print out what is held in each node
		out << temp->data << " ";
		//move temp pointer toward rear of list with next pointer
		temp = temp->next;
		
		}
	
	}

//return what we want to print
return out;

}


/****************************************************************

FUNCTION: front()

ARGUMENTS: none

RETURNS: T qFront->data

NOTES: returns the data stored at the beginning of the list

****************************************************************/

template <class T>

T Queue<T>::front() const throw(out_of_range)

{

if(empty())

	{
	
	throw out_of_range("Queue underflow on front()");
	
	}

else 

	{
	
	return qFront->data;
	
	}

}


/****************************************************************

FUNCTION: back()

ARGUMENTS: none

RETURNS: T "qRear->data"

NOTES: returns the data stored at the end of the queue

****************************************************************/
template <class T>

T Queue<T>::back() const throw(out_of_range)

{

//check if queue is empty
if(empty())

	{
	
	throw out_of_range("Queue underflow on back()");
	
	}

else 

	{
	
	//create temp1 pointer to node to go through linked list starting from front
	Node<T> *temp1 = qFront;
	//use while loop to loop through linked list, and stop when node next to
	//temp1 is NULL
	while (temp1 -> next != NULL)
		
		{
		
		//move temp1 one step back to end of list
		temp1 = temp1->next;
		
		}
	//return what is stored in the last node of the queue
	return temp1->data;
	
	}

}

/****************************************************************

FUNCTION: pop()

ARGUMENTS: none

RETURNS: void

NOTES: removes node from front of queue

****************************************************************/


template <class T>

void Queue<T>::pop() throw(out_of_range)

{

//check if we have an empty list
if(empty())

	throw out_of_range("Queue underflow on pop()");
	
else

	{
	
	//create temp1 pointer to node which points at the front of queue
	
	Node<T> *temp1;
	temp1 = qFront;
	
	//move effect front of queue to next position towards rear
	qFront = qFront->next;
	//delete node temp1 points to
	delete temp1;
	//decrement queueSize data member
	queueSize--;	
	
	}

}


#endif


