#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

class Account
{
protected:
    int accountNumber;
    string holderName;
    double balance;
    Transaction history[100];
    int transactionCount;

public:
    Account(int accNo, string Name, double bal);
    virtual void deposit(double amount);
    virtual void withdraw(double amount) = 0;
    virtual void display() const = 0;
    double getBalance() const;
    virtual void accountType() = 0;
    void showTransactions();
    virtual ~Account();
};

#endif