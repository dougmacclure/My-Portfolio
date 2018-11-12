//*********************************************************
// Doug MacClure
// CSCI340 Section 3
// Assignment 7 
// Due: 3/27/13
//
//*********************************************************





#include "prog7.h"
#include "binTree.h"
#include "/home/onyuksel/courses/340/common/340.h"
#include "binTreeNode.h"


using namespace std;



const vector < int > A { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12,
        13, -14, 15 };
const vector < float > B { 0.5, 1.75, -3, 4.25, 5.50, -6.75, 8, 9.25,
        -10.5 };
const vector < string > C { "This", "is", "a", "list", "of", "string",
        "objects." };





int main()
{
binTree < int > first;
    for ( unsigned i = 0; i < A.size ( ); i++ )
        first.insert ( A [ i ] );
    first.inorder ( increase );


    cout << "first:"; header ( first );
    inOrder ( first, "first" ); cout << endl;

    binTree < int > second ( first );
    second.inorder ( decrease );

    first.clear ( );
    cout << "first:"; header ( first );
    cout << "second:"; header ( second );
    inOrder ( second, "second" ); cout << endl;

    binTree < float > third, fourth;
    for ( unsigned i = 0; i < B.size ( ); i++ )
        third.insert ( B [ i ] );

    cout << "third:"; header ( third );
    third.inorder ( increase );
    inOrder ( third, "third" ); cout << endl;

    fourth = third;
    cout << "fourth:"; header ( fourth );
    fourth.inorder ( decrease );
    inOrder ( fourth, "fourth" ); cout << endl;

    binTree < string > fifth;
    for ( unsigned i = 0; i < C.size ( ); i++ )
        fifth.insert ( C [ i ] );

    cout << "fifth:"; header ( fifth );
    binTree <string> sixth = fifth;
    cout << "sixth:"; header ( sixth );
    inOrder ( sixth, "sixth" );
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
























