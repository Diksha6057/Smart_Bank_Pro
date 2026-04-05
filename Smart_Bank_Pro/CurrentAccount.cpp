
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
    if (amount <= 0) {
        cout << "Invalid amount!" << endl;
        return;
    }
    if (amount <= balance + overdraftLimit)
    {
        balance -= amount;
         if (transactionCount < 100)
            history[transactionCount++] = Transaction("Withdrawal", amount);
        cout << "Withdrawal successful. New Balance: " << balance << endl;
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






void CurrentAccount::applyServiceCharge(double charge) {
    if (charge <= 0) {
        cout << "Invalid service charge!" << endl;
        return;
    }
    if (charge <= balance) {
        balance -= charge;
        if (transactionCount < 100)
            history[transactionCount++] = Transaction("Service Charge", charge);
        cout << "Service charge of " << charge << " applied. New Balance: " << balance << endl;
    } else {
        cout << "Insufficient balance for service charge." << endl;
    }
}



void CurrentAccount::accountType()
{
    cout << "This is a Current Account." << endl;
}