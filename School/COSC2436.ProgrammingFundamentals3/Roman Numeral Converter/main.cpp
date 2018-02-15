/**
    @file main.cpp
    @author Ethan D. Hann
    @date 2-9-2016
    @version 1.0
*/

#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>


using namespace std;

//Prototyping the functions for later use.
void information();
void choices();
int toIntegerEquivalent(string characters);
bool checkInputString(string characters);

//an enum variable that holds the values of each roman numeral
enum roman_numeral_enum {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000};

/*
    a string of the roman numerals - used to check if the user has entered actual
    roman numeral letters and not just random characters.
*/
string roman_numerals = "IVXLCDM";

int main()
{
    /*
       do-while loop continues running unless user has entered option
       3 to quit.
    */
    int choice = 0;
    do
    {
        choices();
        cout << "Choice Number: ";
        cin >> choice;

        //switch statement to create an easy menu system
        switch (choice)
        {
            //case 1 - shows information to user
        case 1:
            {
                system("cls");
                information();
                break;
            }
            //case 2 - first checks inputted roman numeral, then converts it into an integer.
        case 2:
            {
                system("cls");
                string roman = "";
                cout << "Enter a Roman Numeral: ";
                cin >> roman;
                if ((checkInputString(roman)) == true)
                {
                    int converted_str = toIntegerEquivalent(roman);
                    cout << roman << " : " << converted_str << endl;
                    system("PAUSE");
                    break;
                }
                else
                {
                    cout << "Invalid Roman Numeral!" << endl;
                    system("PAUSE");
                    break;
                }
            }
            //case 3 - exits the program.
        case 3:
            {
                system("cls");
                cout << "Goodbye :)" << endl;
                break;
            }
            //default - called when a choice is entered that is not either 1, 2, or 3.
        default:
            {
                system("cls");
                cout << "Invalid Choice. Please try again..." << endl;
                system("PAUSE");
            }
        }

    } while (choice != 3);

}

/**
    Converts a Roman Numeral to its integer equivalent.
    @param roman_input  any roman number (follows rules and must also be within range 1 - 4999)
    @return string
*/
int toIntegerEquivalent(string roman_input)
{
    int integer = 0;
    for (int i = 0; i < roman_input.size(); i++)
    {
        switch (roman_input.at(i))
		{
			case 'M':
			    {
                    integer += M;
                    break;
			    }
			case 'D':
			    {
			        integer += D;
                    break;
			    }
			case 'C':
			    {
			        integer += C;
                    break;
			    }
			case 'L':
			    {
			        integer += L;
			        break;
			    }
			case 'X':
			    {
			        integer += X;
			        break;
			    }
			case 'V':
			    {
			        integer += V;
			        break;
			    }
			case 'I':
				{
				    integer += I;
				    break;
				}
		}
    }
    return integer;
}

/**
    Checks for valid Roman Numerals entered by user.
    @param characters  any string
    @return true if string is valid; false if string is not valid
*/
bool checkInputString(string characters)
{
    int counter = 0;
    char character;
    for (int i = 0; i < characters.length(); i++)
    {
        character = characters.at(i);
        if (roman_numerals.find_first_of(character) != -1)
        {
            continue;
        }
        else
        {
            counter += 1;
        }
    }
    if (counter > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
    Displays information about the program.
    @param NULL
    @return NULL
*/
void information()
{
    system("cls");
    cout << "Roman Numeral Converter will convert from Roman Numerals to Integers." << endl;
    cout << "Remember, the Roman Numerals must be in CAPITAL letters." << endl;
    cout << "Programmer: Ethan Hann" << endl;
    cout << "Version 1.1" << endl;
    system("PAUSE");
}

/**
    Displays main menu to user.
    @param NULL
    @return NULL
*/
void choices()
{
    system("cls");
    cout << "Please Select an Option Using Its Number" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Information" << endl;
    cout << "2. Roman Numeral --> Integer" << endl;
    cout << "3. Exit Program" << endl;
}
