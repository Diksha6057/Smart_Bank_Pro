// SavingsAccount inherits from Account.
#ifndef SAVINGSACCOUNT_H // header guard
#define SAVINGSACCOUNT_H // header guard

#include "Account.h" //bringing here code from Account.h

class SavingsAccount : public Account // INHERITANCE
{
private: // Can be used only inside class
    double interestRate;

public:                                                              // Can be used outside class
    SavingsAccount(int accNo, string name, double bal, double rate); // const.

    void calculateInterest();
    void display() const override;
};

#endif // header guard