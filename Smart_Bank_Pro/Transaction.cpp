#include "Transaction.h"

#include <iostream>
#include <string>
using namespace std;

// Default constructor
Transaction::Transaction() {
    type = "";
    amount = 0;
}

// Parameterized constructor
Transaction::Transaction(string t, double a) {
    type = t;
    amount = a;
}

// Display transaction details
void Transaction::show() const {
    cout << "Transaction: " << type
         << " | Amount: " << amount << endl;
}