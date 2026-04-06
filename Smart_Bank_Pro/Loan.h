#ifndef LOAN_H
#define LOAN_H
#include "Account.h"
#include <string>

class LoanAccount : public Account {
private:
    double principalAmount;
    double interestRate;
public:

    LoanAccount(int accNo, std::string holderName, double principal, double rate);
    
    void deposit(double amount) override; 
    void withdraw(double amount) override; 
    void display() const override;
    void accountType() override;
};
#endif
