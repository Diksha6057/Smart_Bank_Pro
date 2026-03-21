//.cpp=implementation of how it works=source file(containing actual woking code fun def,prg logic,main()fun)
#include "Account.h" //bringing acc class def into this file

Account::Account(int accNo, string name, double bal) // constructor(class name--constructor name)
{
    accountNumber = accNo;
    holderName = name;
    balance = bal;
}
void Account::deposit(double amount)
{
    balance += amount;
    cout << "Amount deposited successfully." << endl;
}
void Account::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawal successful." << endl;
    }
    else
    {
        cout << "Insufficient balance." << endl;
    }
}
void Account::display() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}
double Account::getBalance() const {
    return balance;
}
Account::~Account() // destructor
{
}