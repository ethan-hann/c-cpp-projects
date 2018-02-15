/**

@file main.cpp

@author Ethan Hann

@date 4-7-2016

@version 1.0

*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

vector<string> generate_substrings(string s);
int main()
{
    /*
    Using a do-while loop ensures that the loop will execute at least once.
    The errors variable is true as long as the user enters a word with only one character.
    */
    bool errors = true;
    do
    {
        //Get a string to find the substrings
        cout << "This program will find all substrings of a given word. It will also tell you how ";
        cout << "many substrings there are. Only one word is considered. Strings with spaces are not considered." << endl;
        cout << "--------------------------------------------------" << endl;

        cout << "To find substrings, enter a single string: ";
        string word = "";
        cin >> word;

        /*
        If string is valid, i.e. greater than one character, errors is set to false.
        The function 'generate_substrings' is called with the word as the argument and after
        a vector is returned, the for loop iterates through it to print out the list of
        substrings that were found along with how many substrings there are in the word.
        The list is formatted using iomanip.
        */
        if (word.length() > 1)
        {
            errors = false;
            vector<string> substrings = generate_substrings(word);
            int number_of_substrings = substrings.size();
            cout << "" << endl;
            cout << "" << endl;

            cout << "There are " << number_of_substrings << " substrings in the word " << word << "." << endl;
            cout << "Substrings" << endl;
            cout << setw(20) << setfill('-') << left << "-" << endl;
            for (unsigned int i = 0; i < substrings.size(); i++)
            {
                cout << setfill(' ') << setw(word.size()) << right << substrings[i] << '\t' << setw(10) << left << (i + 1) << endl;
            }
            system("pause");
        }
        else
        {
            cout << "ERROR: Please enter a string that has more than 1 character." << endl;
            errors = true;
        }
    } while (errors);
}

/**
    This function will find all substrings of a given string.

    @param string, the string to find all substrings
    @return vector, a vector with all substrings of the string
*/
vector<string> generate_substrings(string s)
{
    //Creating an empty vector which will be populated by the substrings.
    vector<string> substrings = {};

    //The index that the substring should start at.
    unsigned int begin_index = 0;

    /*
    This while loop ensures that every character of the string is visited. It will continue
    until the beginning index is equal to the size of the string. (i.e. a string that has a
                                                                   size of 5; the loop will
                                                                   continue until begin_index
                                                                   is equal to 5.)
    */
    while (begin_index != s.size())
    {
        /*
        This for loop is what actually creates the substrings.
        The first substring is created at (0,0) where begin_index and
        end_index are both equal to 0. After the loop ends (when all substrings containing
                                                            the first character of the string
                                                            have been created),
        the beginning index is incremented by one and the loop starts again.
        It continues until all substrings have been created. The last substring will
        always be the same as the last character of the string.
        */
        for (unsigned int end_index = 0; end_index <= s.size(); end_index++)
        {
            /*
            In order to ensure that there are no duplicate substrings,
            the previous substring is found and the lengths of the current
            substring and previous substring are compared. If they are the
            same, they must be the same substring therefore the current
            substring is not added to the vector. The current substring is
            also checked to make sure it is not empty.
            */
            string substring = s.substr(begin_index, end_index);
            string previous_substring = s.substr(begin_index, (end_index - 1));
            if (substring.empty())
            {
                continue;
            }
            else if (substring.length() == previous_substring.length())
            {
                continue;
            }
            else
            {
                substrings.push_back(substring);
            }
        }
        begin_index++;
    }
    //The vector of created substrings is returned by this function.
    return substrings;
}
