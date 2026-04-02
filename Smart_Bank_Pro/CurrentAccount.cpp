
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
    history[transactionCount] = Transaction("Withdraw", amount);
transactionCount++;
}
void CurrentAccount::calculateInterest()
{
    cout << "Current accounts usually have no interest." << endl;
}
void CurrentAccount::display() const {
    Account::display();
    cout << "Overdraft Limit: " << overdraftLimit << endl;
}
void CurrentAccount::accountType()
{
    cout << "Account Type: Current Account" << endl;
}