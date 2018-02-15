/**
@main.cpp

@author Ethan Hann

@date 4/9/2015

@version 3.0
*/

#include <iostream>
#include "Account.h"
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <sstream>

using namespace std;

/**
   Displays a nice menu to the user.
*/
void menu()
{
   cout << " ------------------------------------------- " << endl;
   cout << "|        What would you like to do?         |" << endl;
   cout << "| 1. Query the name and balance on account. |" << endl;
   cout << "| 2. Deposit funds into account.            |" << endl;
   cout << "| 3. Withdraw funds from account.           |" << endl;
   cout << "| 4. Change account holder's name.          |" << endl;
   cout << "| 5. Exit the program.                      |" << endl;
   cout << " ------------------------------------------- " << endl;
}

/**
   Converts a string to a double if the string contains appropiate characters.
   @param string s - the string to be converted.
   @return 1.00 - string is not valid
   @return d - converted string if string is valid
*/
double str_to_double(string s)
{
   /*
   Iterate through the string, s, and test if each character is letter or anything other
   than a number. If it is a decimal point, nothing happens and iteration continues. If the character is not
   a number, return 1.00 and exit the loop.
   */
   for (unsigned int i = 0; i < s.length(); i++)
   {
      if (isalpha(s[i]) || !isalnum(s[i]))
      {
         if (s[i] == '.')
         {
            //Do nothing.
         }
         else
         {
            cout << "That is an invalid number!" << endl;
            return 1.00;
         }
      }
      else
      {
         //Do nothing.
      }
   }
   //Convert the string into a double, d, using stringstream.
   double d = 0.00;
   stringstream ss;
   ss << s;
   ss >> d;
   return d;
}

int main()
{
   //The running variable ensures the user types either yes or no and no other answers
    bool running = true;
    while (running == true)
    {
       //Format the output so that all numbers will show as currency.
       cout << fixed << setprecision(2);

       //Setting the color to be a white background with red text.
       system("COLOR F4");
       cout << " --------------------------- " << endl;
       cout << "|                           |" << endl;
       cout << "| First Choice Credit Union |" << endl;
       cout << "|                           |" << endl;
       cout << " --------------------------- " << endl;
       cout << "" << endl;
       cout << "Open new account?" << endl;

       string answer;
       cin >> answer;

       // If answer does not exactly equal yes , the program exits.
       if (answer == "no" || answer == "No" || answer == "NO")
       {
           cout << "Goodbye..." << endl;
           return 0; // Program exited without errors.
       }
       else if (answer == "yes" || answer == "Yes" || answer == "YES")
       {
          //Information is gathered here. First the name of the account holder is recieved.
          cin.sync();
          cout << "Name: ";
          string account_name;
          getline(cin, account_name);

          /*
          The initial balance is recieved as a string in order to prevent invalid characters
          being accepted as input. Only 5 attempts are given and then program exits.
          */
          string initial_balance_s;
          int counter = 4;
          while (counter >= 0)
          {
             cout << "Initial Balance: $";
             getline(cin, initial_balance_s);
             if (str_to_double(initial_balance_s) == 1.00)
             {
                if (counter == 0)
                {
                   cout << "No attempts left. Please restart program to try again." << endl;
                   exit(0);
                }
                cout << counter << " attempts left." << endl;
                counter--;
             }
             else
             {
                counter = -1;
             }
          }
          //The initial balance string is converted to a double using the function str_to_double(string s).
          double initial_balance_d = str_to_double(initial_balance_s);

          //Create a new object of the Account class with the user specified name and initial balance.
          Account first = Account(account_name, initial_balance_d);

          /*
          Clear the screen and list options to the user. Unless the user quits the program, the options will show
          after every operation (hence the while loop).
          */
          system("cls");
          bool more = true;
          while (more)
          {
              menu();
              cin.clear();
              cout << "Enter the option number: ";
              cin >> answer;

              /*Each option corresponds to an action the user can take on their account.
              Option 1: Displays the account name and current balance.
              Option 2: Allows the user to deposit money into the account.
              Option 3: Allows the user to withdraw money from the account. There is a $5.00 penalty for an attempt to withdraw
              more money than is in the account.
              Option 4: Allows the user to change the name on the account.
              Option 5: Exits the program, deleting the account.
              If the user enters something other than 1-4, an error message is displayed.
              */

              //Get account name and current balance.
              if (answer == "1")
              {
                  system("cls");
                  cout << "Name: " << first.get_name() << endl;
                  cout << "Balance: $" << first.get_balance() << endl;
              }

              //Deposit money into account.
              else if (answer == "2")
              {
                  system("cls");
                  cout << "Current balance: $" << first.get_balance() << endl;
                  cout << "Amount to deposit: $";
                  double amount = 0.00;
                  cin >> amount;
                  int deposit_code = first.deposit(amount);
                  if (deposit_code == 0)
                  {
                     cout << "" << endl;
                     cout << "DONE." << endl;
                     cout << "" << endl;
                     cout << "New balance is: $" << first.get_balance() << endl;
                  }
                  else if (deposit_code == 1)
                  {
                     cout << "Balance remained unchanged: $" << first.get_balance() << endl;
                  }
                  else if (deposit_code == 2)
                  {
                     cout << "Balance remained unchanged: $" << first.get_balance() << endl;
                  }
                  else
                  {
                     cout << "" << endl;
                  }
              }

              //Withdraw money from the account.
              else if (answer == "3")
              {
                  system("cls");
                  cout << "Current balance: $" << first.get_balance() << endl;
                  cout << "Amount to withdraw: $";
                  double amount = 0.00;
                  cin >> amount;
                  int withdrawl_code = first.withdrawl(amount);
                  if (withdrawl_code == 0)
                  {
                     cout << "" << endl;
                     cout << "DONE." << endl;
                     cout << "" << endl;
                     cout << "New balance is: $" << first.get_balance() << endl;
                  }
                  else if (withdrawl_code == 1)
                  {
                     cout << "Balance remained unchanged: $" << first.get_balance() << endl;
                  }
                  else if (withdrawl_code == 2)
                  {
                     cout << "New balance is: $" << first.get_balance() << endl;
                  }
                  else if (withdrawl_code == 3)
                  {
                     cout << "Balance remained unchanged: $" << first.get_balance() << endl;
                  }
                  else if (withdrawl_code == 4)
                  {
                     cout << "Balance remained unchanged: $" << first.get_balance() << endl;
                  }
                  else
                  {
                     cout << "" << endl;
                  }
              }

              //Change the name on the account.
              else if (answer == "4")
              {
                 system("cls");
                 cin.sync();
                 string new_name;
                 cout << "New name: ";
                 getline(cin, new_name);
                 first.change_name(new_name);
                 cout << "" << endl;
              }

              //Exit the program with a friendly message.
              else if (answer == "5")
              {
                 cout << "Have a nice day!" << endl;
                 more = false;
                 running = false;
              }

              //An invalid option number was entered.
              else
              {
                  system("cls");
                  cout << "Invalid request." << endl;
                  cout << "" << endl;
              }
          }
       }

       /*
       This is the else from the very first if statement. It is what happens if the user
       enters something other than yes or no to the initial question.
       */
       else
       {
          cout << "Yes or No..." << endl;
          running = true;
       }
    }

    return 0; // Program exited without errors.
}
