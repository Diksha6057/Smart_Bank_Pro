
#include "CurrentAccount.h"
#include <iostream>
#include <stdexcept>
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
try
{
    if (serviceChargeAmount <= 0)
    {
        throw runtime_error(
            "Invalid service charge amount.");
    }

    balance -= serviceChargeAmount;

    cout << "Service charge applied successfully."
         << endl;
}
catch (const exception& exceptionMessage)
{
    cout << "Exception: "
         << exceptionMessage.what()
         << endl;
}



void CurrentAccount::accountType()
{
    cout << "This is a Current Account." << endl;
}
