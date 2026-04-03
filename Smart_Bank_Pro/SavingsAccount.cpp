#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(int accNo, string name, double bal, double rate)
    : Account(accNo, name, bal)
{
    interestRate = rate;
}

void SavingsAccount::calculateInterest()
{
    double interest = (balance * interestRate) / 100;
    balance += interest;
    cout << "Interest added: " << interest << endl;
}

void SavingsAccount::display() const
{
    Account::display();
    cout << "Interest Rate: " << interestRate << "%" << endl;
}

void SavingsAccount::accountType()
{
    cout << "This is a Savings Account." << endl;
}
void SavingsAccount::withdraw(double amount)
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
