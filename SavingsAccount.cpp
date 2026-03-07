// base class constructor.
#include "SavingsAccount.h" //bringing class def from header file

SavingsAccount::SavingsAccount(int accNo, string name, double bal, double rate) // const.
    : Account(accNo, name, bal)                                                 // const. of base class Account(since this class inherits from it)
{
    interestRate = rate;
}

void SavingsAccount::calculateInterest()
{
    double interest = balance * interestRate / 100; //(bal*interest rate/100)
    balance += interest;
}