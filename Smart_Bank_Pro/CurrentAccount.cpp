
#include "CurrentAccount.h"
#include <iostream>
using namespace std;

CurrentAccount::CurrentAccount(int accNo, string name, double bal, double limit)
    : Account(accNo, name, bal)
{
    overdraftLimit = limit;
}

void CurrentAccount::withdraw(double amount)
{
    if (amount <= balance + overdraftLimit)
    {
        balance -= amount;
        cout << "Withdrawal successful using overdraft if needed." << endl;
    }
    else
    {
        cout << "Withdrawal exceeds overdraft limit." << endl;
    }
}

void CurrentAccount::calculateInterest()
{
    cout << "Current accounts usually have no interest." << endl;
}

void CurrentAccount::display() const
{
    Account::display();
    cout << "Overdraft Limit: " << overdraftLimit << endl;
}

void CurrentAccount::applyServiceCharge(double charge)
{
    if(charge > 0 && charge <= balance)
    {
        balance -= charge;
        cout << "Service charge applied." << endl;
    }
    else
    {
        cout << "Invalid service charge." << endl;
    }
}

void CurrentAccount::accountType()
{
    cout << "This is a Current Account." << endl;
}