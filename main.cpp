#include "Account.h"        // Base class ,include Acc class def from Acc.h file ,connects main.cpp with class.
#include "SavingsAccount.h" //Derived class ,including SavingsAccount content which inherits from Account

#include "CurrentAccount.h" //Another derived class
#include <iostream>
using namespace std;
int main()
{
    SavingsAccount acc1(101, "xyz", 5000, 5); // passing acc details to const.
    CurrentAccount acc2(102, "abc", 8000, 2000);
    acc1.deposit(1000);
    acc1.withdraw(2000);
    acc1.calculateInterest();
    acc1.display(); // from Account class as  SavingsAccount inherit it
    cout << endl;
    acc2.calculateInterest();
    acc2.withdraw(9000);
    acc2.display();
    acc2.applyServiceCharge(200);
    return 0;
}
