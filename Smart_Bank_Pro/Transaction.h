#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;
class Transaction {
private:
    string type;
    double amount;

public:
    Transaction();
    Transaction(string t, double a);
    void show() const;
};

#endif