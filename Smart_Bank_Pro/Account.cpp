//.cpp=implementation of how it works=source file(containing actual woking code fun def,prg logic,main()fun)
#include "Account.h" //bringing acc class def into this file
#include <iostream>
using namespace std;
Account::Account(int accNo, string name, double bal) // constructor(class name--constructor name)
{
    accountNumber = accNo;
    holderName = name;
    balance = bal;
    transactionCount = 0;
}
void Account::deposit(double amount)
{
    try {
        if(amount <= 0)
            throw "Invalid deposit amount!";

        balance += amount;
        history[transactionCount] = Transaction("Deposit", amount);
transactionCount++;
        cout << "Amount deposited successfully." << endl;
    }
    catch(const char* msg) {
        cout << msg << endl;
    }
}
void Account::withdraw(double amount)
{
    try {
        if(amount <= 0)
            throw "Invalid amount!";

        if(amount > balance)
            throw "Insufficient balance!";

        balance -= amount;
        history[transactionCount] = Transaction("Withdraw", amount);
transactionCount++;
        cout << "Withdrawal successful." << endl;
    }
    catch(const char* msg) {
        cout << msg << endl;
    }
}
void Account::showTransactions()
{
    cout << "\n--- Transaction History ---\n";
    for(int i = 0; i < transactionCount; i++)
    {
        history[i].show();
    }
}


void Account::display() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}
// Getter Function for Balance
double Account::getBalance() const {
    return balance;
}
Account::~Account() // destructor
{
}

