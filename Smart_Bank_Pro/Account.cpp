#include "Account.h"
#include <iostream>
using namespace std;

// Constructor
Account::Account(int accNo, string name, double bal)
{
    accountNumber = accNo;
    holderName = name;
    balance = bal;
    transactionCount = 0;
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
    if (transactionCount < 100)
        history[transactionCount++] = Transaction("Deposit", amount);
    cout << "Amount deposited successfully. New Balance: " << balance << endl;
   
    
}
// Display
void Account::display() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}
// Show Transactions
void Account::showTransactions()
{
    if(transactionCount == 0)
    {
        cout << "No transactions yet." << endl;
        return;
    }
    cout<<"Transaction History:"<<endl;
    for(int i = 0; i < transactionCount; i++)
    {
        history[i].show();
    }
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