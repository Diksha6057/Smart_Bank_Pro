#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
using namespace std;

class Transaction {
private:
    string type;
    double amount;

public:
    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void show() {
        cout << "Transaction: " << type 
             << " | Amount: " << amount << endl;
    }
};

#endif