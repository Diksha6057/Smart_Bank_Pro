#ifndef LOAN_H
#define LOAN_H
#include "Account.h"
#include <string>

class LoanAccount : public Account {
private:
    double principalAmount;
    double interestRate;
public:
//constructor to initialize loan account with negative balance (loan amount)
    LoanAccount(int accNo, std::string holderName, double principal, double rate);
    //override base class functions to handle loan-specific behavior
    void deposit(double amount) override; 
    void withdraw(double amount) override; 
    void display() const override;
    void accountType() override;
};
#endif
