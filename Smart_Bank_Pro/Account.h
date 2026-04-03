//.h=structure(wt exists) header file(class decla,  fun decla, structure of prg:dont contain logic just tell wt fun exists)
#ifndef ACCOUNT_H // if not defined, define ACCOUNT_H to prevent multiple inclusions of this header file, protects file from double use
#define ACCOUNT_H
#include <iostream>
#include <string> // to store text like names
using namespace std;
class Account
{                      // class to describe acc no,name,balance
protected:             // variables can be used in this class as well as child classes
    int accountNumber; // every obj will have these data members
    string holderName;
    double balance;

public:                                          // funs can be used outside class
    Account(int accNo, string Name, double bal); // constructor(runs automatically when obj created)
  virtual  void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display() const; // fun decl. to print acc details.virtual means fun can be changed later in child class:polymorphism.by const only data will be read not modified
     double getBalance() const; 
    virtual ~Account();           // destructor runs qhen obj is destroyed
};
#endif // closes prrotection started at top