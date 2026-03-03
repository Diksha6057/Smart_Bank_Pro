#include<iostream>
#include<string>
using namespace std;
class Account{
protected:
int accountNumber;
string accountHolderName;
double balance;
public:
Account(int accNum, string accHolderName, double initialBalance) {
    virtual void calculateInterest()=0;
    virtual void displlay() const;
    virtual ~Account() 
};
