#include "Loan.h"
#include <iostream>
using namespace std;
LoanAccount::LoanAccount(int accNo, double principal, double rate)
    : Account(accNo, "LoanUser", -principal)
{
    principalAmount = principal;
    interestRate = rate;
}
// Deposit = EMI payment
void LoanAccount::deposit(double amount)
{
    if(amount <= 0)
    {
        cout << "Invalid EMI amount!" << endl;
        return;
    }

    balance += amount;

    cout << "EMI paid: " << amount << endl;
    cout << "Remaining Loan: " << -balance << endl;
}

// Withdraw not allowed
void LoanAccount::withdraw(double amount)
{
    cout << "Error: Cannot withdraw from a Loan Account!" << endl;
}

// Display details
void LoanAccount::display() const
{
    cout << "------------------------" << endl;
    cout << "Loan Account Number: " << accountNumber << endl;
    cout << "Total Loan: " << principalAmount << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Remaining Loan: " << -balance << endl;
    cout << "------------------------" << endl;
}