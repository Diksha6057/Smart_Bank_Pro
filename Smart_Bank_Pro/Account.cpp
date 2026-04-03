

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

// Deposit function
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

void Account::withdraw(double amount)
{
    if(amount <= 0)
    {
        cout << "Invalid amount!" << endl;
    }
    else if(amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawal successful." << endl;
    }
    else
    {
        cout << "Insufficient balance." << endl;
    }
}

void Account::display() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}

double Account::getBalance() const
{
    return balance;
}
Account::~Account()
{
}