#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include "Account.h"
class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, string name, double bal, double limit);
    void withdraw(double amount);
    void calculateInterest();
    void applyServiceCharge(double charge);   // kept from HEAD
    void display() const override;            // improved version
};

#endif