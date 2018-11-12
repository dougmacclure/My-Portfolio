//***********************************************************
// FILE: binTreeNode.h
// Assignment 6
// PURPOSE: contains class definition for binTreeNode
//
//***********************************************************


#ifndef BINTREENODE_H
#define BINTREENODE_H

using namespace std;

template <class T> class binTree; // forward declaration

template <class T> class binTreeNode {
friend class binTree<T>; // class binTree is friend
public:
//constructor
binTreeNode ( const T&x = T ( ), binTreeNode < T >*l=NULL, binTreeNode < T >*r=NULL ):data(x), left(l), right(r){}

private:
T data; // data component
binTreeNode<T> *left, *right; // left and right links
};

#endif
