#include "LoanAccount.h"
#include <iostream>
using namespace std;

LoanAccount::LoanAccount(string accNum, double principal, double rate) 
    : Account(accNum, -principal), principalAmount(principal), interestRate(rate) {}

void LoanAccount::deposit(double amount) {
    balance += amount; 
    cout << "EMI paid: " << amount << " | Remaining Loan: " << -balance << endl;
}

void LoanAccount::withdraw(double amount) {
    cout << "Error: Cannot withdraw from a Loan Account!" << endl;
}

void LoanAccount::display() const {
    cout << "Loan A/C: " << accountNumber << " | Total Loan: " << principalAmount 
         << " | Interest: " << interestRate << "% | Due: " << -balance << endl;
}
