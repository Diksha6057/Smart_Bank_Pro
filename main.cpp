#include "Account.h" //include Acc class def from Acc.h file ,connects main.cpp with class.

int main() {

    Account acc1(101, "xyz", 5000); //calls the constructor nd display() function of acc1: Obj now created in memory
    acc1.display();
    return 0;
}