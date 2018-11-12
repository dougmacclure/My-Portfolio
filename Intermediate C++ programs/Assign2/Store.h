#ifndef STORE_H
#define STORE_H
#include "Product.h"

//**************************************************************
// FILE:	Store.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	9/20/12
//
// PURPOSE: Declares the class Store
//**************************************************************

class Store
{

	Product productAr[30];
	int numProdObjects;

	public:

	Store();
	Store(const char*);
	void print();
	void sortProducts();
	int searchForProduct( char[]);
	void processOrders(const char*);
	
};


#endif

