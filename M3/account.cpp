
// FILENAME:   account.cpp
// PROGRAMMER: Gary J. Blair
// DATE:       4/11/1996
// COMPILER:   MS Visual C++ 2008 Express Edition
// REQUIRED:   demoacct.cpp, account.h, account.cpp 
// PURPOSE:
//   Implementation of account objects.
//   Demonstrate fundamental concepts
//   about classes.

#include <iostream>
#include <stdlib.h>
#include "account.h"

using namespace std;

Account::Account(void)
{
    this->initialized = 0;
}

Account::Account( AccountNumber acct_num,
                  Money acct_bal )
{
    this->initialized = 1;
    this->account_number = acct_num;
    this->account_balance = acct_bal;
}

void   Account::deposit( Money amount )
{
    this->verify_initialization();
    this->account_balance += amount;
}


    /* The use of this in all above function
       definitions is unnecessary. The compiler
       will provide it when we use an
       unqualifed member name in the body of a
       member function of that class. It is never
       wrong to use this, but it is not always
       necessary. There are times when we use this
       to refer to the entire object on which the
       member function is invoked. */

void   Account::withdraw( Money amount )
{
    verify_initialization();
    account_balance -= amount;
}


Account::Money   Account::balance(void)
{
    verify_initialization();
    return account_balance;
}

void   Account::write(void)
{
    verify_initialization();
    cout << account_number << ":"
         << account_balance;
}


void   Account::read(void)
{
    cin >> account_number;
    if (cin.get() != ':')
    {
       cerr << "*** Error reading account:
               no colon.\n";
       exit(1);
    }
    cin >> account_balance;
    initialized = 1;
}

void Account::verify_initialization(void)
{
    if (initialized)
       return;
    else
    {
       cerr << "*** Attempt to use uninitialized
               account.\n";
       exit(1);
    }
}