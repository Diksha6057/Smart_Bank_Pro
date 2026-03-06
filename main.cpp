#include "Account.h" //include Acc class def from Acc.h file ,connects main.cpp with class.

int main() {

    Account acc1(101, "xyz", 5000); //calls the constructor nd display() function of acc1: Obj now created in memory
    acc1.display();
    return 0;
}
#include "SavingsAccount.h" //including SavingsAccount content which inherits from Account

int main() {

    SavingsAccount acc1(101, "xyz", 5000, 5); //passing acc details to const.

    acc1.calculateInterest();
    acc1.display(); //from Account class as  SavingsAccount inherit it

    return 0;
}