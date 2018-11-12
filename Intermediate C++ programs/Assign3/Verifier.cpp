/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 3
   PROGRAMMER: Doug MacClure
   LOGON ID:   z0125061
   DUE DATE:   9/28/2012

   FUNCTION:   This is the class definition file for Verifier's methods.
*********************************************************************/  


#include <cstdlib>
#include "Verifier.h"
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
#include <iostream>


using namespace std;

/****************************************************************

FUNCTION: Verifier::Verifier()

ARGUMENTS: None.

RETURNS: None.

NOTES: Is the default constructor.

****************************************************************/

Verifier::Verifier()
{

for(int i = 0; i < 9; i++)

	{
	
	for (int j = 0; j < 9; j++)
	
		{
	
		sudokuGrid[i][j] = 0;
		
		}
	
	}

}


/****************************************************************

FUNCTION: Verifier::readGrid()

ARGUMENTS: A pointer to a constant character; the constant character is a file.

RETURNS: None.

NOTES: Opens the passed-in input filename, and reads the file into the 2-D array
sudokuGrid[][].

****************************************************************/

void Verifier::readGrid(const char* filename)
{

ifstream inFile;
inFile.open(filename);

if (inFile.fail())

	{
	
	cout << endl << "Error opening file." << endl;
	exit(-1);
	
	}

for(int i = 0; i < 9; i++)
	
	for(int j = 0; j < 9; j++)
	
		inFile >> sudokuGrid[i][j];

inFile.close();

}



/****************************************************************

FUNCTION: Verifier::printGrid()

ARGUMENTS: None.

RETURNS: None.

NOTES: Prints out the sudokuGrid 2-D array in a user-friendly organized format. 

****************************************************************/


void Verifier::printGrid()
{

cout << endl << endl;

cout << "------------------------------------" << endl;

for (int i = 0; i < 9; i++)

		{

		cout << "|";
		for (int j = 0; j < 9; j++)

			{

			cout << " " << sudokuGrid[i][j] << " ";

			if ( (j % 3) == 2)

				cout << " | ";

			}
		
		cout << endl;
		if( (i % 3)== 2)

			{
			cout << "------------------------------------";
			cout << endl;
			}

		}

	cout << endl;
	
	
}
/****************************************************************

FUNCTION: Verifier::verifySolution()

ARGUMENTS: None.

RETURNS: A boolean value.  Value returned is false if the sudokugrid is found
to have repeated numbers in rows, columns, and/or a 3X3 cell.

NOTES: We are using a one dimensional boolean array, isIn, to keep track of each digit that
is used in each row, column and 3X3 cell.  Each time we reach a new row, column, or cell,
we reset isIn's elements to false.  After each row, column, or cell, if we are to place
true in the corresponding digit placement in isIn, and true is already there, we return
the value false, and declare the sudokuGrid to be an incorrect solution.  Otherwise, if
the file input gives us a good sudoku solution, we return true.

****************************************************************/

bool Verifier::verifySolution()
{

bool isIn[10];

int i, j, x, row, col;



//check the rows to make sure we have a good sudoku puzzle

for( row = 0; row < 9; row ++)

	{
	
	for(i = 1; i < 10; i++)

		isIn[i] = false;
	
	for(j = 0; j < 9; j++)
	
		{
		
		if(isIn[(sudokuGrid[row][j])] == false)
		
			isIn[(sudokuGrid[row][j])] = true;
		
		else 
			
			return false;

		}
	
	}	 

//okay so far...



//check the columns to make sure we have a good sudoku puzzle

for ( col = 0; col <9; col++)

	{
	
	for( j = 1; j < 10; j++)

		{
	
		isIn[j] = false;

		}
	
	for( i = 0; i < 9; i++)
	
		{
	
		if(isIn[sudokuGrid[i][col]] == false)
		
			isIn[(sudokuGrid[i][col])] = true;
			
		else 
		
			return false;
		
		}
	

	}

//check the 9 3X3 grids to make sure we have a good sudoku puzzle

for( x = 0; x < 9; x+=3)

	{
	for ( i = 1; i < 10; i++)

		isIn[i] = false;
	
	for( row = 0; row < 9; row++)
		
		{
		
		if((row % 3) == 0)

			for( i = 1; i < 10; i++)

				isIn[i] = false;
		
		for( col = x; col < x+3; col++)
		
			{
			
			if(isIn[sudokuGrid[row][col]] == false)

				{
				
				isIn[sudokuGrid[row][col]] = true;
				}

			else
			
		 		return false;
			
			}
		
		}

	}

return true;

}

