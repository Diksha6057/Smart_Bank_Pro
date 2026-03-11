#include "BankOperations.h"
double BankOperations::deposit(double balance, double amount)
{
    return balance + amount;
}
double BankOperations::withdraw(double balance, double amount)
{
    if(amount > balance)
    {
        cout<<"Insufficient balance"<<endl;
        return balance;
    }
    return balance - amount;
}
double BankOperations::calculateInterest(double balance, double rate)
{
    return balance + (balance * rate / 100);
}