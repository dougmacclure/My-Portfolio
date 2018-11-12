/***************************************************************

	PROGRAM:	Assignment1: Fun With Numerology
	AUTHOR:		Doug MacClure
	LOGON ID:	Z0125061
	DUE DATE:	9/13/2012

	FUNCTION:	Utilizes the "C string" char array to read user info, and passes each char to a function.  Use a function
			to convert elements in a char array into a sum.
	INPUT:		From user/keyboard.
	OUTPUT:		To screen, not saved.  Output is the personality trait associated with the numerology of a user-defined
			name.
	NOTES:		N/A
***************************************************************/

#include <cstdio>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <ctype.h>


using namespace std;

//function prototypes

int convertToNum( char );

int main()
{

//initialize necessary variables and char arrays
char choice;
char name[80] = {0};
int sum = 0;
char numbers[80] = {0};
char newChar;
int newNum;
unsigned int i;

//Inform user of the purpose of the program, and get user to enter a name to be used for the next while loop
cout << "Welcome to the Fun With Numerology Program, where we determine ";
cout << "personality traits based upon the structure of a name" << endl << endl;
cout << "Enter a name: ";

cin.getline(name, 80, '\n');

//loop until user wants to quit

while(true)
	{

	//send chars inputed into name into function

	for(i = 0; i < sizeof(name); i++)

                {
		//add up each number associated with each char to sum
                newChar = name[i];
                newNum = convertToNum(newChar);
                sum += newNum;

                }
	//use while loop to check to see if sum is one of the given vals
	while( sum != -1)

	{

		if (sum == 0)
		{
			cout << endl << "That name has the traits emptiness, nothingess, and blank." << endl;
			sum = -1;

		}

		else if (sum == 1)
		{
			cout << endl << "That name has the traits independence, creativity, originality, dominance, leadership, and impatience." << endl;
			sum = -1;
		}

		else if (sum == 2)
		{
			cout << endl << "That name has the traits quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient." << endl;
			sum = -1;
		}

		else if (sum == 3)
		{
			cout << endl << "That name has the traits charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud." << endl;
			sum = -1;
		}

		else if (sum == 4)
		{
			cout << endl << "That name has the traits harmony, truth, justice, order, discipline, practicality." << endl;
			sum = -1;
		}

		else if (sum == 5)
		{
			cout << endl << "That name has the traits new directions, excitement, change, adventure." << endl;
			sum = -1;
		}

 		else if (sum == 6)
		{
			cout << endl << "That name has the traits love, harmony, perfection, marriage, tolerance, public service" << endl;
			 sum = -1;
		}

		else if (sum == 7)
		{
			cout << endl << "That name has the traits spirituality, completeness, isolation, introspection." << endl;
			sum = -1;
		}

		else if (sum == 8)
		{
			cout << endl << "That name has the traits organization, business, commerce, new beginnings." << endl;
			 sum = -1;
		}

		else if (sum == 9)
		{
			cout << endl << "That name has the traits romantic, rebellious, determined, passionate, compassionate." << endl;
			sum = -1;
		}

		else if (sum == 11)
		{
			cout << endl << "That name has the traits idealism, visionary, inspirational." << endl;
			sum = -1;
		}

		else if (sum == 12)
		{
			cout << endl << "That name has the traits perfectionist, discriminating." << endl;
			 sum = -1;
		}

		else if (sum == 22)
		{
			cout << endl << "That name has the traits builder, leader, humanitarian, practical, honest." << endl;
			sum = -1;
		}

		else
			{
			//convert sum to the char array numbers, then reset sum

			sprintf(numbers, "%d", sum);
			sum = 0;

			//loop through numbers, and send each char to the convertToNum() function
			for(i = 0; i < sizeof(numbers); i++)

        		        {

		                newChar = numbers[i];
		                newNum = convertToNum(newChar);
                		sum += newNum;

		                }


			}

		}
	//check if user wants to quit, or keep going

	cout << endl << "Another? (y/n) ";

	cin >> choice;
	choice = toupper(choice);

	if(choice != 'N' and choice != 'Y')

		{
		while (choice != 'Y' and choice != 'N')
			{

		 	cout << endl << endl << "Enter y or n: ";
			cin >> choice;
			choice = toupper(choice);
			cin.getline(name, 80, '\n');
			}
		}

	else if (choice == 'N')

		{
		sum = -1;
		break;
		}

	else
		//fills up the name array again with a new name, and go through the first while loop again

		{
		cout << endl << "Enter a name: ";
		sum = 0;

		cin.getline(name, 80, '\n');
		cin.getline(name, 80, '\n');

		}



	}




return 0;
}


/****************************************************************

FUNCTION: int convertToNum( char )

ARGUMENTS: char ch

RETURNS: num

NOTES: Takes each char one at a time, and converts the character into
a numerical value.

****************************************************************/

int convertToNum( char ch )

{

int num;
char upperCase;


if (isalpha(ch))

	{

	upperCase = toupper(ch);

	num = upperCase - 64;

	}

else if (isdigit(ch))

	{

	num = ch - 48;

	}

else
	{

	num = 0;

	}

return num;

}

