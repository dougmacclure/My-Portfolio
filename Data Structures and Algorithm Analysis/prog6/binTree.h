#ifndef BINTREE_H
#define BINTREE_H

#include "/home/onyuksel/courses/340/common/340.h"
#include "binTreeNode.h"
#include "prog6.h"

using namespace std;

template <class T> class binTree{

public:
binTree();
bool empty() const; // checks if tree empty
int size() const; // returns no of nodes
int height() const; // returns height of tree
virtual void insert( const T& ); // inserts a node in shortest subtree
void inorder(void ( * )( T& )); // inorder traversal of tree
void preorder(void ( * )( T& )); // preorder traversal of tree
void postorder(void ( * )( T& )); // postorder traversal of tree
protected:
binTreeNode < T >* root; // root of tree
private:
int size( binTreeNode<T>* ) const; // private version of size ( )
int height( binTreeNode<T>* ) const; // private version of height( )
void insert( binTreeNode<T>*&, const T& ); // private version of insert( )
void inorder( binTreeNode<T>*, void ( * )( T& )); // private version of inorder ( )
void preorder( binTreeNode<T>*, void ( * )( T& ));// private version of preorder ( )
void postorder( binTreeNode<T>*, void ( * )( T& ));// private version of postorder ( )
};



//*********************************************************************
// FUNCTION: binTree()
// ARGUMENTS: none
// RETURNS: none
// NOTES: The default constructor for binTree class
//
//*********************************************************************


template <class T>
binTree<T>::binTree()
{

root = NULL;

}


//*********************************************************************
// FUNCTION: empty()
// ARGUMENTS: none
// RETURNS: bool
// NOTES: returns whether or not the size() function returns 0; if it does
// return true else return false
//*********************************************************************


template <class T>
bool binTree<T>::empty() const
{

return size() == 0;

}


//*********************************************************************
// FUNCTION: size()
// ARGUMENTS: none
// RETURNS: int
// NOTES: the public version of the size() binTree member function. This
// one returns the result of the private size() function when passing in
// the root node.
//*********************************************************************


template <class T>
int binTree<T>::size() const
{

return size(root);

}

//*********************************************************************
// FUNCTION: height()
// ARGUMENTS: none
// RETURNS: int
// NOTES: the public version of the height() binTree member function. This 
// one returns the result of the private height() function when passing in
// the root node.
//*********************************************************************


template <class T>
int binTree<T>::height() const
{

return height(root);

}

//*********************************************************************
// FUNCTION: insert()	
// ARGUMENTS: const T &newitem
// RETURNS void
// NOTES: The public virtual insert member function for the binTree class.
// Inserts a new node according to the desired shape of binary tree by
// calling the private insert() member function if btree object is nonempty
//*********************************************************************


template<class T>
void binTree<T>::insert(const T& newitem)
{

//if binary tree is not empty

if(root != NULL)

	{

	//call private insert() member function and pass in root node and newitem to insert a new node

	insert(root, newitem);

	}

else
	{
	
	//otherwise binary tree is empty, so allocate memory for a new node, set left & right to NULL, then set
	//root's data to passed in newitem
	root = new binTreeNode<T>;
	root->left = NULL;
	root->right = NULL;
	root->data = newitem;
	}	


}


//*********************************************************************
// FUNCTION: inorder()
// ARGUMENTS: void (*f)(T&)
// RETURNS void
// NOTES: Is the public binTree inorder member function.  Calls private version
// and passes in root node and the function that was passed in as an argument.
//*********************************************************************



template<class T>
void binTree<T>::inorder(void(*f)(T&))
{

inorder(root, f);

}


//*********************************************************************
// FUNCTION: preorder()
// ARGUMENTS: void (*f)(T&)
// RETURNS void
// NOTES: Is the public binTree preorder member function.  Calls private version
// and passes in root node and the function that was passed in as an argument.
//*********************************************************************


template<class T>
void binTree<T>::preorder(void(*f)(T&))
{

preorder(root, f);

}


//*********************************************************************
// FUNCTION: postorder()
// ARGUMENTS: void (*f)(T&)
// RETURNS: void
// NOTES: Is the public binTree postorder member function.  Calls private version
// and passes in root node and the function that was passed in as an argument.
//*********************************************************************



template<class T>
void binTree<T>::postorder(void(*f)(T&))
{

postorder(root, f);

}


//*********************************************************************
// FUNCTION:  size() 
// ARGUMENTS: binTreeNode<T> *bnode
// RETURNS: int
// NOTES: the private, recursive version of the size member function.  
//*********************************************************************


template<class T>
int binTree<T>::size(binTreeNode<T>* bnode)const
{

int count = 1;


//if passed in node is NULL (base case), return 0
if(bnode == NULL)

	return 0;

else

	{
	//otherwise, return the size of the left side of the binary tree starting at bnode plus
	//the right side of the binary tree starting at bnode plus 1 (for bnode, not NULL by
	//recursively calling size and passing in the right or left linked node from bnode.
	//this is done until all external nodes have been reached, then this function collapses
	//to base case
	count += size(bnode->left);
	count += size(bnode->right);
	return count; 

	}

}


//*********************************************************************
// FUNCTION: height()
// ARGUMENTS: binTreeNode<T> *bnode
// RETURNS: int
// NOTES: the private, recursive version of the height member function
//
//*********************************************************************


template <class T>
int binTree<T>::height(binTreeNode<T>* bnode)const
{

int leftHgt = 0;
int rightHgt = 0;

//if passed in node is NULL (base case), return 0

if(bnode == NULL)

	return 0;

else

	{

		//otherwise, return 1 + the maximum of when height is recursively called
		//and has the left linked  node passed into it and right linked node passed
		//into it.  This is done until all external nodes have been reached.  Then
		//the base case is reached, and we return the longest path from root to external node
		leftHgt = height(bnode->left);
		rightHgt = height(bnode->right);

		if (rightHgt > leftHgt) 
	
			return 1 + rightHgt;

		else

			return 1 + leftHgt;
				

	}
}


//*********************************************************************
// FUNCTION: insert()
// ARGUMENTS: binTreeNode<T> *&bnode, const T &newItem
// RETURNS: void
// NOTES: the private version of the insert member function, used to insert
// a new node into a binary tree recursively
//*********************************************************************


template <class T>
void binTree<T>::insert(binTreeNode<T> *&bnode, const T&newItem)
{


	//if the height of the binary tree starting from passed in node bnode
	//on the left is less than or equal to the height on the right,
	//and the left linked node from bnode is nonempty, call insert and
	//pass in the left linked node frombnode, and then repass in newItem

	if(height(bnode->left) <= height(bnode->right) && bnode->left!=NULL)

			
	
		insert(bnode->left, newItem);

	//if the height of the left tree is <= right tree, and left linked node 
	//from bnode is NULL, then allocate memory for a new node in the left
	//linked node from bnode, place newItem into its data, then from left linked
	//node, set right and left linked nodes to NULL

	else if (height(bnode->left) <= height(bnode->right) && bnode->left==NULL)

		{
			
		bnode->left = new binTreeNode<T>;
		bnode->left->data = newItem;
		bnode->left->left = NULL;
		bnode->left->right = NULL;

		}

	//if the height of the binary tree starting from passed in node bnode
        //on the left is greater than the height on the right,
        //and the right linked node from bnode is nonempty, call insert and
        //pass in the right linked node frombnode, and then repass in newItem


	else if (height(bnode->left) > height(bnode->right) && bnode->right!=NULL)

		insert(bnode->right, newItem);

	//if the height of the left tree is > height of right tree, and right linked node
        //from bnode is NULL, then allocate memory for a new node in the right
        //linked node from bnode, place newItem into its data, then from right linked
        //node, set right and left linked nodes to NULL


	else if (height(bnode->left) > height(bnode->right) && bnode->right==NULL)

		{

		bnode->right = new binTreeNode<T>;
		bnode->right->data = newItem;
		bnode->right->left = NULL;
		bnode->right->right = NULL;

		}




}


//*********************************************************************
// FUNCTION: inorder()
// ARGUMENTS: binTreeNode<T> *bnode, void (*f)(T&)
// RETURNS: void
// NOTES: the private version of the inorder member recursive function.  Used for
// an inorder traversal of a binary tree
//*********************************************************************


template <class T>
void binTree<T>::inorder(binTreeNode<T> *bnode, void(*f)(T&))
{

//if passed in node is empty do nothing(base case) otherwise

if(bnode != NULL)

	{
	
	//call inorder, passing in the left linked node of bnode, and repass in
	//same unary function

	inorder(bnode->left, f);
	//call passed in unary function passing in bnode's(parent) data 
	f(bnode->data);

	//call inorder, passing in the right linked node of bnode, and repass in
	//same unary function
	inorder(bnode->right, f);

	}

}


//*********************************************************************
// FUNCTION:  preorder()
// ARGUMENTS: binTreeNode<T> *bnode, void (*f)(T&)
// RETURNS: void
// NOTES: the private version of the preorder member recursive function.  Used
// for a preorder traversal of a binary tree
//*********************************************************************


template <class T>
void binTree<T>::preorder(binTreeNode<T> *bnode, void(*f)(T&))
{


//if passed in node is empty do nothing(base case) otherwise

if(bnode!= NULL)

	{

	//call passed in unary function passing in bnode's (parent) data

	f(bnode->data);
	//call preorder, passing in the left linked node of bnode, and repass in
        //same unary function

	preorder(bnode->left, f);

	//call preorder, passing in the right linked node of bnode, and repass in
	//same unary function
	preorder(bnode->right, f);

	}

}


//*********************************************************************
// FUNCTION: postorder()
// ARGUMENTS: binTreeNode<T> *bnode, voide (*f)(T&)
// RETURNS: void
// NOTES: the private version of the postorder member recursive function.  Used
// for a postorder traversal of a binary tree
//*********************************************************************


template <class T>
void binTree<T>::postorder(binTreeNode<T> *bnode, void(*f)(T&))
{

//if passed in node is empty do nothing(base case) otherwise

if(bnode != NULL)

	{

	//call postorder, passing in the left linked node of bnode, and
	//repass in same unary function
	postorder(bnode->left, f);

	//call postorder, passing in the right linked node of bnode, and repass
	//in same unary function
	postorder(bnode->right, f);
	//call passed in unary function passing in bnode's(parent) data
	f(bnode->data);

	}

}


#endif
