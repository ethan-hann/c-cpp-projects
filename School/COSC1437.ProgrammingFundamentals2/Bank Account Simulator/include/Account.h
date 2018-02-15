#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
public:

    //Constructor for an Account object. Must provide a name and initial balance.
    Account(string name, double initial_balance);

     /**
        Allows the user to deposit funds into account.
        @param depo_amount Amount to deposit into account.
        @return either 1 or 0 - depending on if the user tried to withdraw a negative amount
    */
    int deposit(double depo_amount);

    /**
        Allows the user to withdraw funds from account.
        @param with_amount Amount to withdraw from account.
        @return either 1 or 0; 1 = error; 0 = no error;
    */
    int withdrawl(double with_amount);

    /**
        Allows the user to query the name on the account.
        @return string name - the name on account
    */
    string get_name() const;

    /**
        Allows the user to query the current balance in the account.
        @return double balance - the current balance in the account.
    */
    double get_balance() const;

    /**
        Allows the user to change the name on the account.
        @param string new_name - the new name on the account.
    */
    void change_name(string new_name);


private:
    string name;
    double amount;
    double balance;
};

#endif // ACCOUNT_H
