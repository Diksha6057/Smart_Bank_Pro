#include "Loan.h"
#include <iostream>
#include <stdexcept>
using namespace std;

LoanAccount::LoanAccount(int accNo, string holderName, double principal, double rate)
    : Account(accNo, holderName, -principal)
{
    principalAmount = principal;
    interestRate = rate;
}

void LoanAccount::deposit(double amount)
{
    try
    {
        if (amount <= 0)
        {
            throw runtime_error(
                "Invalid EMI amount.");
        }

        balance += amount;

        if (transactionCount < 100)
        {
            history[transactionCount++] =
                Transaction("EMI Payment", amount);
        }

        cout << "EMI paid: "
             << amount
             << endl;

        if (balance >= 0)
        {
            cout << "Loan fully repaid! Congratulations!"
                 << endl;
        }
        else
        {
            cout << "Remaining Loan: "
                 << -balance
                 << endl;
        }
    }
    catch (const exception& exceptionMessage)
    {
        cout << "Exception: "
             << exceptionMessage.what()
             << endl;
    }
}

void LoanAccount::withdraw(double amount)
{
    cout << "Error: Cannot withdraw from a Loan Account!" << endl;
}

void LoanAccount::display() const
{
    cout << "--- Loan Account ---" << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Holder Name    : " << holderName << endl;
    cout << "Total Loan     : " << principalAmount << endl;
    cout << "Interest Rate  : " << interestRate << "%" << endl;
    cout << "Remaining Loan : " << (balance < 0 ? -balance : 0) << endl;
}

void LoanAccount::accountType()
{
    cout << "Account Type: Loan Account" << endl;
}
