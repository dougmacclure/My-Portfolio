#ifndef PRODUCT_H
#define PRODUCT_H

//**************************************************************
// FILE:	Product.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	9/20/12
//
// PURPOSE: 
//**************************************************************

class Product
	{
	char prodCode[12];
	char prodName[46];
	double prodPrice;
	int prodQuantity;
	
	public:
	Product();
	Product( char[], char[], double, int);
	char* getProductCode();
	char* getName();
	double getPrice();
	int getQuantity();
	void setPrice(double);
	void setQuantity(int);
	int fulfillOrder(int);
	void print();
	};

#endif

