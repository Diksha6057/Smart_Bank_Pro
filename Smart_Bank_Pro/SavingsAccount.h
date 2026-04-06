#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate);

    void calculateInterest();
    void display() const override;
    void accountType() override;
    void withdraw(double amount) override;
};

#endif