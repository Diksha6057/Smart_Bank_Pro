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
void Account::withdraw(double amount)
{
    if(amount <= 0)
    {
        cout << "Invalid amount!" << endl;
        return;
    }
    if(amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawal successful." << endl;
    }
    else
    {
        cout << "Insufficient balance." << endl;
    }
}

void Account::showTransactions()
{
    if(transactionCount == 0)
    {
        cout << "No transactions yet." << endl;
        return;
    }
    for(int i = 0; i < transactionCount; i++)
    {
        history[i].show();
    }
}
// Destructor
Account::~Account()
{
}