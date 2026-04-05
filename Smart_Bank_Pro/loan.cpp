#include "Loan.h"
#include <iostream>
using namespace std;
LoanAccount::LoanAccount(int accNo,  string holderName, double principal, double rate)
    : Account(accNo,  holderName,-principal)


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



    if (transactionCount < 100)
        history[transactionCount++] = Transaction("EMI Payment", amount);
    cout << "EMI paid: " << amount << endl;
    if (balance >= 0) {
        cout << "Loan fully repaid! Congratulations!" << endl;
    } else {
        cout << "Remaining Loan: " << -balance << endl;
    }

    
}

// Withdraw not allowed
void LoanAccount::withdraw(double amount)
{
    cout << "Error: Cannot withdraw from a Loan Account!" << endl;
}

// Display details

void LoanAccount::display() const {
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