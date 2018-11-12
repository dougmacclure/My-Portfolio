/***************************************************************

	PROGRAM:	Assignment 2
	AUTHOR:		Doug MacClure
	LOGON ID:	Z0125061
	DUE DATE:	9/20/2012
	
	FUNCTION:	This file is a source code definition for the class Store
	INPUT:
	OUTPUT:
	NOTES:
***************************************************************/

#include "Store.h"
#include "Product.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/****************************************************************

FUNCTION: Store::Store

ARGUMENTS: None.

RETURNS: None.

NOTES: Is the default constructor.

****************************************************************/

Store::Store()
{

numProdObjects = 0;

}

/****************************************************************

FUNCTION: Store::Store

ARGUMENTS: const char* pointName

RETURNS: None.

NOTES: Is the alternate constructor, which reads an array of chars that contains
the name of an existing database file.

****************************************************************/

Store::Store(const char* pointName)
{

ifstream inFile;
//inFile.open(pointName, ios::binary);
inFile.open(pointName);

if(inFile.fail())
	{
	
	cout << endl << "File did not open." << endl;
	exit(-1);
	
	}
	
inFile.read((char*)this, sizeof(Store));


inFile.close();
sortProducts();
}

/****************************************************************

FUNCTION: Store::print()

ARGUMENTS: None.

RETURNS: None.

NOTES: calls print() from Product class to print arrays of Product objects

****************************************************************/


void Store::print()
{

cout << "Product Inventory Listing" << endl;
cout << "Product Code  ";
cout << "Name                                          ";
cout << "Price ";
cout << "    Qty." << endl;

for( int i = 0; i < numProdObjects; i++)
	
	productAr[i].print();

}


/****************************************************************

FUNCTION: Store::sortProducts()

ARGUMENTS: None.

RETURNS: None.

NOTES: 

****************************************************************/

void Store::sortProducts()
{

int i, j;
Product bucket;

 for (i = 1; i < numProdObjects; i++)
      {
      bucket = productAr[i];

      for (j = i; (j > 0) && (strcmp(productAr[j-1].getProductCode(),bucket.getProductCode()) > 0); j--)
         productAr[j] = productAr[j-1];

      productAr[j] = bucket;
      }
   
}

/****************************************************************

FUNCTION: Store::sortProducts()


ARGUMENTS: None.

RETURNS: None.

NOTES: 

****************************************************************/

int Store::searchForProduct(char searchCode[])
{

int low = 0;
   int high = numProdObjects - 1;
   int mid;

   while (low <= high)
      {
      mid = (low + high) / 2;

      if (strcmp(searchCode, productAr[mid].getProductCode()) == 0)
         return mid;

      else if (strcmp(searchCode, productAr[mid].getProductCode()) < 0)
         high = mid - 1;
		 
      else
         low = mid + 1;
      }

   return -1;

}

/****************************************************************

FUNCTION: Store::processOrders()


ARGUMENTS: const char* orderFile

RETURNS: None.

NOTES: 

****************************************************************/

void Store::processOrders(const char* orderFile)
{

ifstream inFile;
char orderNumber[7];
char productCode[12];
int orderQuantity;
int numShipped;

inFile.open(orderFile);

if(inFile.fail())
	{
	
	cout << endl << "File did not open." << endl;
	exit(-1);
	
	}
	
inFile >> orderNumber;
	
while(inFile)
	{
	
	inFile >> productCode;
	inFile >> orderQuantity;
	
	int index = searchForProduct(productCode);
	if (index == -1)
		cout << endl << "Error processing order." << endl;
	else
		{

		numShipped = productAr[index].fulfillOrder(orderQuantity);
		cout << "Order #" << orderNumber << ": product " << productCode << ", "
		<< numShipped << " of " << orderQuantity << " shipped, order total $" 
		<< productAr[index].getPrice() << endl;
		




		}
		
	inFile >> orderNumber;
	}	 
inFile.close();

}

