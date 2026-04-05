#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <iostream>
using namespace std;

int main()
{
    // Taking user input
    int accNo;
    string name;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Balance: ";
    cin >> bal;

  
// Taking input for Current Account
int accNo2;
string name2;
double bal2;

cout << "Enter Current Account Number: ";
cin >> accNo2;
cout << "Enter Current Account Holder Name: ";
cin.ignore();
getline(cin, name2);
cout << "Enter Current Account Balance: ";
cin >> bal2;

// Creating objects
SavingsAccount savingsAcc(accNo, name, bal, 5);
CurrentAccount currentAcc(accNo2, name2, bal2, 2000);
    
    


    // Polymorphism pointer
    Account* ptr;

    // Array of base class pointers
    Account* accounts[2];
    accounts[0] = &savingsAcc;
    accounts[1] = &currentAcc;

    int choice;
    double amount;

    // Menu-driven program
    do {
        cout << "\nSmart Bank Menu" << endl;
        cout << "1. Deposit in Savings Account" << endl;
        cout << "2. Withdraw from Savings Account" << endl;
        cout << "3. Display Both Accounts (Polymorphism)" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Get Savings Account Balance" << endl;
        cout << "6. Apply Service Charge (Current Account)" << endl;
        cout << "7. Show Transaction History" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                savingsAcc.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                savingsAcc.withdraw(amount);
                break;

            case 3:
                ptr = &savingsAcc;
                ptr->display();

                cout << endl;

                ptr = &currentAcc;
                ptr->display();
                break;

            case 4:
                for(int i = 0; i < 2; i++)
                {
                    accounts[i]->display();
                    cout << endl;
                }
                break;

            case 5:
                cout << "Balance using getter: " << savingsAcc.getBalance() << endl;
                break;

            case 6:
                cout << "Enter service charge: ";
                cin >> amount;
                // apply service charge by withdrawing the amount from the current account
                currentAcc.withdraw(amount);
                break;

            
            case 7:
               cout << "Savings Account Transactions:" << endl;
               savingsAcc.showTransactions();
               break;

               case 8:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 8);

    return 0;
}