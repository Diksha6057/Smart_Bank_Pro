//.cpp=implementation of how it works=source file(containing actual woking code fun def,prg logic,main()fun)
#include "Account.h" //bringing acc class def into this file 

Account::Account(int accNo, string name, double bal)// constructor(class name--constructor name)
 {
    accountNumber = accNo;
    holderName = name;
    balance = bal;
}

void Account::display() const //fun belongs to acc class
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}

Account::~Account() //destructor
{

}