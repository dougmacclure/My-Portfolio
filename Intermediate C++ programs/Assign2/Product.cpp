/***************************************************************

	PROGRAM:	Assignment 2
	AUTHOR:		Doug MacClure
	LOGON ID:	Z0125061
	DUE DATE:	9/20/2012
	
	FUNCTION:	This file is a source code definition for the class Product
	INPUT:
	OUTPUT:
	NOTES:
***************************************************************/
#include "Product.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cstdio>

using namespace std;


/****************************************************************

FUNCTION: Product::Product

ARGUMENTS: None.

RETURNS: None.

NOTES: Is the default constructor.

****************************************************************/

Product::Product()
{
strcpy(prodCode, "");
strcpy(prodName, "");
prodPrice = 0;
prodQuantity = 0;
}


/***************************************************************

FUNCTION: Product::Product

ARGUMENTS: Two char arrays, one representing product codes, the other representing
product name; a double that represents product price, and an int representing the
product quantity.

RETURNS: None.

NOTES: Alternate Product constructor.

***************************************************************/

Product::Product(char newProdCode[], char newProdName[], double newProdPrice, int newProdQuantity)
{
strcpy(prodCode, newProdCode);
strcpy(prodName, newProdName);
setPrice(newProdPrice);
setQuantity(newProdQuantity);
}


/**************************************************************

FUNCTION(S): 1) getProductCode; 2)getName; 3)getPrice; 4)getQuantity

ARGUMENTS: 1), 2), 3), and 4) do not have arguments.

RETURNS: 1) returns a pointer to a char array, representing the product code;
2) returns a pointer to a char array, representing the product name; 3) 
returns a double, the product price; and 4) returns an int, the product quantity.

NOTES: These four methods are the get methods for the Product class, that allow the user
to access the private data memebers.

**************************************************************/

//1)

char* Product::getProductCode()
{
return prodCode;
}

//2)

char* Product::getName()
{
return prodName;
}

//3)

double Product::getPrice()
{
return prodPrice;
}

//4)

int Product::getQuantity()
{
return prodQuantity;
}


/***************************************************************

FUNCTION(S): 1) Product::setPrice; 2) Product::setQuantity

ARGUMENTS: 1) a double representing the new product price; 2) an int
representing the new product quantity

RETURNS: 1) and 2) return nothing.

NOTES: These two methods are the set methods for the Product class,
that allow the user to alter the private data members if allowed to.

***************************************************************/

//1)

void Product::setPrice(double newPrice)
{

if (newPrice >= 0)

	prodPrice = newPrice;

else
	prodPrice = 0;

}

//2)

void Product::setQuantity(int newQuan)
{

if (newQuan >= 0)

	prodQuantity = newQuan;

else

	prodQuantity = 0;

}




int Product::fulfillOrder(int quanOrdered)

{

int quanShipped;

if (quanOrdered < 0)

	{

	cout << endl << "Error: cannot have a negative order quantity." << endl;
	quanShipped = 0;

	}

else if (quanOrdered <= prodQuantity)

	{
	quanShipped = quanOrdered;
	prodQuantity -= quanOrdered;
	}

else
	{
	quanShipped = prodQuantity;
	prodQuantity = 0;
	}
return quanShipped;
}



void Product::print()
{

cout << left << setw(14) << prodCode; 
cout << setw(46) << prodName;
cout << right << setw(6) << fixed << setprecision(2) << prodPrice;
cout << setw(6) << prodQuantity << endl;

}

