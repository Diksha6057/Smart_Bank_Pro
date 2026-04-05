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
void SavingsAccount::withdraw(double amount) {
    const double MIN_BALANCE = 500.0; // minimum balance required
    if (amount <= 0) {
        cout << "Invalid amount!" << endl;
        return;
    }
    if (balance - amount < MIN_BALANCE) {
        cout << "Cannot withdraw! Minimum balance of " << MIN_BALANCE << " must be maintained." << endl;
        return;
    }
    balance -= amount;
    if (transactionCount < 100)
        history[transactionCount++] = Transaction("Withdrawal", amount);
    cout << "Withdrawal successful. New Balance: " << balance << endl;
}