//Doug MacClure
//CSCI330-3 
//Assignment 8
//FILE: binSTree.h
//PURPOSE: contains class definition for binary search tree drive class


#ifndef BINSTREE_H
#define BINSTREE_H

#include "binTree.h"
#include "binTreeNode.h"
#include "/home/onyuksel/courses/340/common/340.h"

using namespace std;

//want binSTree to inherit binTree publicly 
template < class T >
class binSTree : public binTree < T > {
public:

//use default constructor given by compiler
void insert( const T&  ); // insert node with value x
bool search ( const T& ) const; // searches leaf with value x
bool remove ( const T&  ); // removes leaf with value x

private:

binTreeNode<T>* inOrderSearch(binTreeNode<T>*, const T &) const;
void insert( binTreeNode < T >*&, const T& ); // private version of insert
bool search ( binTreeNode < T >*, const T& ) const; // private version of search
void remove ( binTreeNode < T >*&, const T& ); // private version of remove
bool leaf ( binTreeNode < T >* ) const; // checks if node is leaf

};

//******************************************************************************
// FUNCTION: insert()
// ARGUMENTS: const T&x
// RETURNS: void
// NOTES the public insert function for binSTree class simply calls private insert
// version, passing in the current instance of the class's root and x 
//******************************************************************************


template<class T>
void binSTree<T>::insert(const T& x)
{

insert(this->root, x);

}


//******************************************************************************
// FUNCTION: search
// ARGUMENTS: const T&x
// RETURNS: bool
// NOTES: returns the result of passing in the current instance of the class's root and
// x to the private search function
//******************************************************************************


template<class T>
bool binSTree<T>::search(const T& x) const
{

return search(this->root, x);

}



//******************************************************************************
// FUNCTION: remove()
// ARGUMENTS: const T& x
// RETURNS: bool
// NOTES: calls public search function to see if x exists within the binary search tree.
// If so, call private remove() function passing in root and x and return true.  Else, return false.
//******************************************************************************


template<class T>
bool binSTree<T>::remove(const T& x)
{

if (search(x))

	{

	remove(this->root, x);
	return true;

	}

else

	{
//	cout << " couldn't remove " << x;

	return false;
	}

}


//******************************************************************************
// FUNCTION: insert()
// ARGUMENTS: binTreeNode<T> *&bnode, const T&newData
// RETURNS: void
// NOTES:  "overwrites" the binTree insert() function, since we set the public binTree
// insert function to virtual.  
//******************************************************************************



template<class T>
void binSTree<T>::insert(binTreeNode<T> *&bnode, const T&newData)

{

//check if passed in node is NULL, if so create a new mode

if (bnode == NULL)

	{

	bnode = new binTreeNode<T>(newData);
	bnode->left = NULL;
	bnode->right = NULL;

	}

//otherwise, the current node already exists within the tree, so we need to find 
//the appropriate place within binary search tree

else

	{

	//if the item we want to insert is greater than current node's data, recursively
	//call insert function passing in current node's right linked node, otherwise 
	//pass in left linked node

	if ( newData > bnode->data)

		insert(bnode->right, newData);
	
	else if (newData < bnode->data)

		insert(bnode->left, newData);
	

	}
}


//******************************************************************************
// FUNCTION: search()
// ARGUMENTS: binTreeNode<T> *bnode, const T&targetVal
// RETURNS: bool
// NOTES: if during/after traversal of tree we find targetVal in tree, return true;
// else return false.
//******************************************************************************


template<class T>
bool binSTree<T>::search(binTreeNode<T> *bnode, const T &targetVal) const
{

//continue loop as long as current node is not NULL

while(bnode != NULL)

	{

	//if we have a match of current node's data with target value, return true

	if(bnode->data == targetVal)

		
		{

		return true;

		}

	//otherwise, go to right linked node if current node's data is less than target
	//value, or left linked node if it is the other case

	else

		{

		if(targetVal > bnode->data)

			bnode = bnode->right;

		else if(targetVal < bnode->data)

			bnode = bnode->left;

		}
	}

//we have exited loop and reached a NULL node/dead end, so node does not exist in tree: return false

//cout << " couldn't find " << targetVal;
return false;

}


//******************************************************************************
// FUNCTION: leaf()
// ARGUMENTS: binTreeNode<T> *bnode
// RETURNS: bool
// NOTES: checks if passed in node is a leaf, ie, not NULL with left and right linked
// nodes set to NULL
//******************************************************************************


template<class T>
bool binSTree<T>::leaf(binTreeNode<T> *bnode) const
{

if(bnode != NULL)
	
	return bnode->left == NULL && bnode->right == NULL;

else

	return false;

}

//******************************************************************************
// FUNCTION: remove()
// ARGUMENTS: binTreeNode<T> *&bnode, const T& targetVal
// RETURNS: void
// NOTES: the private version of the remove function.  We already checked if targetVal
// exists in public remove() function, so we can assume node we want to remove exists.
//******************************************************************************


template <class T>
void binSTree<T>::remove(binTreeNode<T> *&bnode, const T& targetVal)
{
//Need to consider 3 base cases:
//1) The node to be removed is a leaf
//2) The node to be removed has only one child
//3) the node to be removed has two children

 
//if current node doesn't contain targetVal, we want to traverse binary search tree
//in the usual manner according to how we ordered it in our insert function

        if (targetVal < bnode->data)

       		remove(bnode->left, targetVal);
	
        else if (targetVal > bnode->data)
       
                remove(bnode->right, targetVal);
       

//otherwise, current node is node we want to delete
        else
        {
 
                binTreeNode<T> *temp;
 
	//case 1
		if(leaf(bnode))

			{

			delete bnode;
			bnode = NULL;
	
			}
	//case 2

//here, we want to bypass the current node, then delete it.  simply have a temporary node
//hold whichever next node is not null, delete current node, then connect current node to
//temporary node again

                else if (bnode->left==NULL)
                {
                        temp = bnode->right;
                        delete bnode;
                        bnode = temp;
                	temp = NULL;

		}
                else if (bnode->right==NULL)
                {
                        temp = bnode->left;
                        delete bnode;
                        bnode = temp;
			temp = NULL;
                }
        //case 3
	        else    

//we want to find bnode's predecessor, to do so we do a simple inorder traversal recursively
	                {
			//have our temporary pointer pointed towards bnode's right child
        
	                temp = bnode->right;
			
			//initialize our lag pointer to a NULL node to avoid seg fault

                        binTreeNode<T> *lag = NULL;
 
			//go to left side

                        while(temp->left!=NULL)
                        
				{
                        
			        lag = temp;
                                temp = temp->left;
                        
				}
			//"visit node"        

	               	bnode->data = temp->data;

			//if the pointer before temporary pointer is not NULL, i.e., we iterated
			//through while loop at least once, recursively call remove again passing
			//in the node that contained bnode's predecessor, lag->left 
                        if (lag != NULL)
                               remove(lag->left, lag->left->data);

			//otherwise, we didn't iterate through while loop, so
                        else
                                remove(bnode->right, bnode->right->data);
                }
        }
}






#endif
