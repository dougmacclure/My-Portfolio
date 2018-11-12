//*********************************************************
// Doug MacClure
// CSCI340 Section 3
// Assignment 6
// Due: 2/19/13
//
//*********************************************************





#include "prog6.h"
#include "binTree.h"
#include "/home/onyuksel/courses/340/common/340.h"
#include "binTreeNode.h"


using namespace std;

int main()
{

//initialize three empty binTree objects 

binTree<int> first;
binTree<float> second;
binTree<string> third;

//fill our three binTree objects with corresponding elements of our 3 vectors

for(unsigned vi = 0; vi < A.size(); vi++)
	{

	first.insert(A[vi]);
	}

for(unsigned vf = 0; vf < B.size(); vf++)
	{

	second.insert(B[vf]);

	}

for(unsigned vs = 0; vs < C.size(); vs++)
	{

	third.insert(C[vs]);

	}


//increase each node in binTree object first by 1 with a preorder traversal
first.preorder(increase);

//print out desired output
cout << "first: ";
header(first);
cout << endl;
inOrder(first, "first");
cout << endl;
preOrder(first, "first");
cout << endl;
postOrder(first, "first");
cout << endl;

//decrease each node in binTree object second by 1 with a postorder traversal
second.postorder(decrease);

//print out desired output
cout << endl << "second: ";
header(second);
cout << endl;
inOrder(second, "second");
cout << endl;
preOrder(second, "second");
cout << endl;
postOrder(second, "second");
cout << endl;

//printout desired output
cout << endl << "third: ";
header(third);
cout << endl;
inOrder(third, "third");
cout << endl;
preOrder(third, "third");
cout << endl;
postOrder(third, "third");
cout << endl;

return 0;
}


//*********************************************************************
// FUNCTION:  print()
// ARGUMENTS: T &x
// RETURNS: void
// NOTES: Unary function used to print its argument to standard output
//
//*********************************************************************



template <class T> void print(T &x)
{
cout << x << ' ';
}



//*********************************************************************
// FUNCTION: increase()
// ARGUMENTS: T &x
// RETURNS: void
// NOTES: Unary function used to increment its argument by 1
//
//*********************************************************************


template<class T> void increase(T &x)
{
x++;
}


//*********************************************************************
// FUNCTION: decrease()
// ARGUMENTS: T &x
// RETURNS: void
// NOTES: Unary function used to decrement its argument by 1
//
//*********************************************************************


template<class T> void decrease(T &x)
{
x--;
}

//*********************************************************************
// FUNCTION: isEmpty()
// ARGUMENTS: const binTree<T> &btree
// RETURNS: void
// NOTES: Checks if passed in btree object is empty by calling binTree member function
// empty() and prints a message indicating whether or not the object is empty.
//*********************************************************************


template < class T > void isEmpty ( const binTree < T >&btree )
{

if(!btree.empty())
	cout << "tree is not empty" << endl;

else
	cout << "tree is empty" << endl;
}


//*********************************************************************
// FUNCTION: header()
// ARGUMENTS: binTree<T> &btree
// RETURNS void
// NOTES: calls isEmpty(), then prints desired output of btree's size and
// height with binTree member functions size() & height().
//*********************************************************************


template < class T > void header ( const binTree < T >&btree )
{

isEmpty(btree);
cout << "\tno of nodes     =  " << btree.size() << endl
     << "\theight of tree  =  " << btree.height() << endl;


}


//*********************************************************************
// FUNCTION: inOrder()
// ARGUMENTS: binTree<T> &btree, const string &name
// RETURNS: void 
// NOTES: prints desired output, then calls the binTree member function  
// inorder and passes the unary function print(), so btree is printed in
// an in order traversal.
//*********************************************************************


template < class T > void inOrder ( binTree < T >&btree, const string &name )
{

cout << "The elements of '" << name << "' in inorder:" << endl;
cout <<"\t";

btree.inorder(print);

}


//*********************************************************************
// FUNCTION:  preOrder()
// ARGUMENTS: binTree<T> &btree, const string &name
// RETURNS: void
// NOTES: prints desired output, thencalls the binTree member functon
// preorder and passes the unary function print(), so btree is printed in
// a pre order traversal
//*********************************************************************


template < class T > void preOrder ( binTree < T > &btree, const string &name )
{

cout << "The elements of '" << name << "' in preorder:" << endl;
cout <<"\t";

btree.preorder(print);

}

//*********************************************************************
// FUNCTION:  preOrder()
// ARGUMENTS: binTree<T> &btree, const string &name
// RETURNS: void
// NOTES: prints desired output, then calls the binTree member functon
// postorder and passes the unary function print(), so btree is printed in
// a post order traversal
//*********************************************************************


template < class T > void postOrder ( binTree < T > &btree, const string &name )
{

cout << "The elemnts of '" << name << "' in postorder:" << endl;
cout <<"\t";

btree.postorder(print);

}
























