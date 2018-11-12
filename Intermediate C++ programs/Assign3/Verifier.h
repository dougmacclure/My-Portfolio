//**************************************************************
// FILE:	Product.h
// AUTHOR:	Doug MacClure
// LOGON ID:	z0125061
// DUE DATE:	9/20/12
//
// PURPOSE: 	This is the header file for the class definition of Verifier.
//**************************************************************

#ifndef VERIFIER_H
#define VERIFIER_H

class Verifier
{

int sudokuGrid[9][9];

public:

Verifier();
void readGrid(const char*);
void printGrid();
bool verifySolution();


};

#endif

