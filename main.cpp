#include<iostream>
#include "BankOperations.h"
using namespace std;

int main()
{
    double balance, amount, rate;

    cout<<"Enter balance: ";
    cin>>balance;

    cout<<"Enter deposit amount: ";
    cin>>amount;
    balance = BankOperations::deposit(balance, amount);

    cout<<"Enter withdrawal amount: ";
    cin>>amount;
    balance = BankOperations::withdraw(balance, amount);

    cout<<"Enter interest rate: ";
    cin>>rate;
    balance = BankOperations::calculateInterest(balance, rate);

    cout<<"Final balance: "<<balance<<endl;

    return 0;
}