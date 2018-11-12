/***************************************************************

	PROGRAM:	Assignment1: Fun With Numerology
	AUTHOR:		Doug MacClure
	LOGON ID:	Z0125061
	DUE DATE:	9/13/2012

	FUNCTION:	Utilizes the C++ string class to store info into strings.  Use a function
			to convert a string of letters into a string of numbers
	INPUT:		From user.
	OUTPUT:		Sent to screen, not saved.  Output is the personality trait associated with
			the numerology of a given name.
	NOTES:		N/A
***************************************************************/

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

//initialize necessary variables & strings
char choice;
string name = "";
int sum = 0;
string numbers = "";
char newChar;
int newNum;
unsigned int i;

//inform user of purpose of program, and read input for the while loop

cout << "Welcome to the Fun With Numerology Program, where we determine ";
cout << "personality traits based upon the structure of a name" << endl << endl;
cout << "Enter a name: ";

//use getline() because whitespace may be a part of a name
getline(cin, name);

//keep loop going until user wishes to stop entering names
while(true)
	{

	//loop through string and send  chars inputed into name into function

	for(i = 0; i < name.size(); i++)

                {

                newChar = name[i];
                newNum = convertToNum(newChar);
	//sum will be used to check for personality traits
                sum += newNum;

                }

	//loop until sum is one of the given vals
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
			//if sum isn't one of given vals, convert sum to a string, then reset sum

			ostringstream convToString;
			convToString << sum;
			numbers = convToString.str();
			sum = 0;

			//loop through string, and send each char to function, and add to sum until done 
			for(i = 0; i < numbers.size(); i++)

        		        {

		                newChar = numbers[i];
		                newNum = convertToNum(newChar);
                		sum += newNum;

		                }


			}

		}

	//offer user chance to enteranother name
	cout << endl << "Another? (y/n) ";

	cin >> choice;
	choice = toupper(choice);

	if(choice != 'N' and choice != 'Y')

		{
		while (choice != 'Y' and choice != 'N')
			{

			cout << endl << "Enter y or n: ";
			cin >> choice;
			choice = toupper(choice);
			getline(cin,name);
			}
		}

	else if (choice == 'N')

		{
		sum = -1;
		break;
		}

	else

		{
		cout << endl << endl << "Enter a name: ";
		sum = 0;

	//need extra getline() since user will have pressed newline key which is applied to next getline(), unfortunately
		getline(cin, name);
		getline(cin, name);

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

