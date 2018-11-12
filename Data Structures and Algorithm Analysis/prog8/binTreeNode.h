//***********************************************************
// FILE: binTreeNode.h
// Assignment 8
// PURPOSE: contains class definition for binTreeNode
//
//***********************************************************


#ifndef BINTREENODE_H
#define BINTREENODE_H

typedef enum{left_higher, right_higher, equal_height} BF;


using namespace std;

template <class T> class binTree; // forward declarations
template <class T> class binSTree;

template <class T> class binTreeNode {
friend class binTree<T>; // class binTree is friend
friend class binSTree<T>;
public:
//constructor
binTreeNode ( const T&x = T ( ), binTreeNode < T >*l=NULL, binTreeNode < T >*r=NULL ):data(x), left(l), right(r){}
/*virtual void get_balance(const BF &b) = 0;
virtual BF set_balance() = 0;*/


private:
T data; // data component
binTreeNode<T> *left, *right; // left and right links
};

#endif
