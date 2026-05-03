#include "SavingsAccount.h"
#include <iostream>
#include <stdexcept>
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
     if (transactionCount < 100)
        history[transactionCount++] = Transaction("Interest", interest);
    cout << "Interest added: " << interest << " | New Balance: " << balance << endl;
}
 
void SavingsAccount::display() const
{   cout << "--- Savings Account ---" << endl;
    Account::display();
    cout << "Interest Rate: " << interestRate << "%" << endl;
}

void SavingsAccount::accountType()
{
    cout << "This is a Savings Account." << endl;
}
void SavingsAccount::withdraw(double amount)
{
    try
    {
        const double minimumBalance = 500.0;

        if (amount <= 0)
        {
            throw runtime_error(
                "Invalid withdrawal amount.");
        }

        if (balance - amount < minimumBalance)
        {
            throw runtime_error(
                "Minimum balance of 500 must be maintained.");
        }

        balance -= amount;

        if (transactionCount < 100)
        {
            history[transactionCount++] =
                Transaction("Withdrawal", amount);
        }

        cout << "Withdrawal successful. New Balance: "
             << balance
             << endl;
    }
    catch (const exception& exceptionMessage)
    {
        cout << "Exception: "
             << exceptionMessage.what()
             << endl;
    }
}
