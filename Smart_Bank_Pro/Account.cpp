#include "Account.h"
#include <iostream>
using namespace std;

// Constructor
Account::Account(int accNo, string name, double bal)
{
    accountNumber = accNo;
    holderName = name;
    balance = bal;
}

// Deposit
void Account::deposit(double amount)
{
    if(amount <= 0)
    {
        cout << "Invalid amount!" << endl;
        return;
    }

    balance += amount;
    cout << "Amount deposited successfully." << endl;
}

// Display
void Account::display() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}

// Getter
double Account::getBalance() const
{
    return balance;
}

// Destructor
Account::~Account()
{
}