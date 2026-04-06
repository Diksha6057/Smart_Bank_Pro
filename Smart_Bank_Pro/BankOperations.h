#ifndef BANKOPERATIONS_H
#define BANKOPERATIONS_H

class BankOperations {
public:
    static double deposit(double balance, double amount);
    static double withdraw(double balance, double amount);
    static double calculateInterest(double balance, double rate);
};

#endif