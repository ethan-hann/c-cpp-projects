#include "Account.h"
#include <iostream>
#include <string>
#include <ctype.h>


using namespace std;

Account::Account(string acct_name, double initial_balance)
{
    name = acct_name;
    balance = initial_balance;
}


int Account::deposit(double depo_amount)
{
    amount = depo_amount;

    if (!cin)
    {
       cout << "That is not a valid amount!" << endl;
       return 2;
    }
    else if (amount < 0)
    {
       cout << "You can't deposit a negative amount!" << endl;
       return 1;
    }
    else
    {
       balance += amount;
       return 0;
    }

}

int Account::withdrawl(double with_amount)
{
    amount = with_amount;

    if (!cin)
    {
       cout << "That is not a valid amount!" << endl;
       cout << "" << endl;
       return 3;
    }
    else if (amount < 0)
    {
       cout << "You can't withdraw a negative amount!" << endl;
       cout << "" << endl;
       return 1;
    }

    else if (amount > balance)
    {
        balance -= 5.00;
        if (balance <= 0)
        {
           balance = 0;
        }
        cout << "Insufficient funds. You have been charged a $5.00 penalty." << endl;
        cout << "" << endl;
        return 2;
    }
    else if (balance <= 0)
    {
       cout << "You are broke. There are no funds to withdraw!" << endl;
       cout << "" << endl;
       return 4;
    }
    else
    {
        balance -= amount;
        return 0;
    }
}

double Account::get_balance() const
{
    return balance;
}

string Account::get_name() const
{
    return name;
}

void Account::change_name(string new_name)
{
   name = new_name;
}
