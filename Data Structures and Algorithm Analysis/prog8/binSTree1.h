#ifndef BINSTREE_H
#define BINSTREE_H

#include "binTree.h"
#include "binTreeNode.h"
#include "/home/onyuksel/courses/340/common/340.h"

using namespace std;


template < class T >
class binSTree : public binTree < T > {
public:

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



template<class T>
void binSTree<T>::insert(const T& x)
{

insert(this->root, x);

}


template<class T>
bool binSTree<T>::search(const T& x) const
{

return search(this->root, x);

}

template<class T>
bool binSTree<T>::remove(const T& x)
{

if (search(this->root, x))

	{

	remove(this->root, x);
	return true;

	}

else

	return false;

}


template<class T>
void binSTree<T>::insert(binTreeNode<T> *&bnode, const T&newData)

{

if (bnode == NULL)

	{

	bnode = new binTreeNode<T>(newData);
	bnode->left = NULL;
	bnode->right = NULL;

	}

else

	{

	if ( newData > bnode->data)

		insert(bnode->right, newData);
	
	else if (newData < bnode->data)

		insert(bnode->left, newData);
	

	}

/*if (bnode->data == newData)

	{

	cout << "Error.  Cannot insert value into tree since it already exists";
	exit(-1);

	}
*/
}


template<class T>
bool binSTree<T>::search(binTreeNode<T> *bnode, const T &targetVal) const
{

while(bnode != NULL)

	{

	if(bnode->data == targetVal)

		
		{

		return true;

		}

	else

		{

		if(targetVal > bnode->data)

			bnode = bnode->right;

		else if(targetVal < bnode->data)

			bnode = bnode->left;

		}
	}
return false;

}

template<class T>
bool binSTree<T>::leaf(binTreeNode<T> *bnode) const
{

if(bnode != NULL)
	
	return bnode->left == NULL && bnode->right == NULL;

else

	return false;

}


template <class T>
void binSTree<T>::remove(binTreeNode<T> *&bnode, const T& targetVal)
{
//Need to consider 3 base cases:
//1) The node to be removed is a leaf
//2) The node to be removed has only one child
//3) the node to be removed has two children

//if(bnode == NULL)

//	{
//	cout << "error";
//	bnode = this->root;
//	cout << "error";

//	}
if(bnode->data > targetVal && bnode->left != NULL)
        {

        remove(bnode->left, targetVal);
        }
else if(bnode->data < targetVal && bnode->right != NULL)
        {

        remove(bnode->right, targetVal);

        }





else if(bnode->data == targetVal)
	{

//case 1

	if((leaf(bnode)))

		{

		delete bnode;
		bnode = NULL;

		}

	else if(bnode == NULL)

		cout << "error";

//case 2
	else if(bnode->left == NULL)

		{
		binTreeNode<T>* temp = bnode->right;
		delete bnode;
		bnode = temp;
		temp = NULL;
		

		}

	 else if(bnode->right == NULL)

               	{
	        binTreeNode<T>* temp = bnode->left;
                delete bnode;
               bnode = temp;
                temp = NULL;

	        }
/*

else if(bnode->data == targetVal && bnode->right == NULL && leaf(bnode->left))

        {
cout << 2;


        binTreeNode<T> *temp = bnode->left;
        bnode->data = temp->data;
        delete temp;
        temp = NULL;

        }


else if(bnode->data == targetVal && bnode->left == NULL && leaf(bnode->right))

        {
cout << 2;

        binTreeNode<T> *temp = bnode->right;
        bnode->data = temp->data;
        delete temp;
        temp = NULL;

        }

else if(bnode->left->data == targetVal && bnode->left->left == NULL && bnode->left->right != NULL)

        {
cout << 2;

        binTreeNode<T>*temp = bnode->left;
        bnode->left = temp->right;
        delete temp;
        temp = NULL;

        }

else if(bnode->left->data == targetVal && bnode->left->right == NULL && bnode->left->left != NULL)

        {
cout << 2;

        binTreeNode<T>*temp = bnode->left;
        bnode->left = temp->left;
        delete temp;
        temp = NULL;

        }

else if(bnode->right->data == targetVal && bnode->right->left == NULL && bnode->right->right != NULL)

        {
cout << 2;

        binTreeNode<T>*temp = bnode->right;
        bnode->right = temp->right;
        delete temp;
        temp = NULL;

        }


else if(bnode->right->data == targetVal && bnode->right->left != NULL && bnode->right->right == NULL)

        {
cout << 2;

        binTreeNode<T>*temp = bnode->right;
        bnode->right = temp->left;
        delete temp;
        temp = NULL;

        }



	else

        	{

        //Find successor:  do an inorder traversal, as succcessor is the node visited right after it
                cout << 3;
                binTreeNode<T>* temp = bnode->right;
                binTreeNode<T>* lag;
                while(temp->left != NULL)

                        {
                        cout << "4";
                        lag = temp;
                        temp = temp->left;

                        }

                bnode->data = temp->data;
                cout << "found it";

                if(lag != NULL)

                       remove(lag->left, lag->left->data);
			//remove(this->root, lag->left->data);

                else
                       // remove(bnode->right, bnode->right->data);
                	remove(this->root, bnode->right->data);
		}
*/
        }


}






#endif
