#ifndef LOANACCOUNT_H
#define LOANACCOUNT_H
#include "Account.h"
#include <string>

class LoanAccount : public Account {
private:
    double principalAmount;
    double interestRate;
public:
    LoanAccount(std::string accNum, double principal, double rate);
    void deposit(double amount) override; 
    void withdraw(double amount) override; 
    void display() const override;
};
#endif
