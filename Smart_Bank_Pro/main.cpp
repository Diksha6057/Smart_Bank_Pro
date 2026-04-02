#include "Account.h"        // Base class ,include Acc class def from Acc.h file ,connects main.cpp with class.
#include "SavingsAccount.h" //Derived class ,including SavingsAccount content which inherits from Account

#include "CurrentAccount.h" //Another derived class
#include <iostream>
using namespace std;
int main()
{ //Taking user input
    int accNo;
    string name;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Balance: ";
    cin >> bal;
    
 //Creating objects
    SavingsAccount acc1(accNo, name, bal, 5);
    CurrentAccount acc2(102, "abc", 8000, 2000);
//Pointer (Polymorphism demo)
    Account* ptr;
    //Storing in array (polymorphism)  Array of base class pointers
    Account* accounts[2];
    accounts[0] = &acc1;
    accounts[1] = &acc2;



    int choice;
    double amount;
    // Menu-driven program
    do {
        cout << "Smart Bank Menu"<<endl;
        cout << "1. Deposit in Savings Account"<<endl;
        cout << "2. Withdraw from Savings Account"<<endl;
        cout << "3. Display Savings Account"<<endl;
        cout << "4. Display all Accounts"<<endl;
        cout << "5. Get Savings Account Balance"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

         switch(choice)
        {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc1.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc1.withdraw(amount);
                break;

           case 3:
                //Using pointer (polymorphism)
                ptr = &acc1;
                ptr->display();

                cout << endl;

                ptr = &acc2;
                ptr->display();
                break;

            case 4:
                //Using array of pointers
                for(int i = 0; i < 2; i++)
                {
                    accounts[i]->display();
                    cout << endl;
                }
                break;

            case 5:
                cout << "Balance using getter: " << acc1.getBalance() << endl;
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}