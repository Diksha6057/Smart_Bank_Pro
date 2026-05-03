#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "Loan.h"
#include "InterestCalculator.h"
#include "BankUtilities.h"
#include <iostream>
using namespace std;


void printLine() {
    cout << "================================" << endl;
}

int main()
{

     printLine();
    cout << "   Welcome to Smart Bank Pro   " << endl;
    printLine();
    BankUtilities<double> bankUtility;


 // ---- Create Savings Account ----
    int accNo1;
    string name1;
    double bal1;
    cout << "\n--- Create Savings Account ---" << endl;
    cout << "Enter Account Number : "; cin >> accNo1;
    cin.ignore();
    cout << "Enter Holder Name    : "; getline(cin, name1);
    cout << "Enter Opening Balance: "; cin >> bal1;
    SavingsAccount savingsAcc(accNo1, name1, bal1, 5.0); // 5% interest rate

    // ---- Create Current Account ----
    int accNo2;
    string name2;
    double bal2;
    cout << "\n--- Create Current Account ---" << endl;
    cout << "Enter Account Number : "; cin >> accNo2;
    cin.ignore();
    cout << "Enter Holder Name    : "; getline(cin, name2);
    cout << "Enter Opening Balance: "; cin >> bal2;
    CurrentAccount currentAcc(accNo2, name2, bal2, 2000.0); // 2000 overdraft limit

    // ---- Create Loan Account ----
    int accNo3;
    string name3;
    double loanAmt, loanRate;
    cout << "\n--- Create Loan Account ---" << endl;
    cout << "Enter Account Number  : "; cin >> accNo3;
    cin.ignore();
    cout << "Enter Holder Name     : "; getline(cin, name3);
    cout << "Enter Loan Amount     : "; cin >> loanAmt;
    cout << "Enter Interest Rate % : "; cin >> loanRate;
    LoanAccount loanAcc(accNo3, name3, loanAmt, loanRate);


    // Polymorphism pointer
    Account* ptr;

    // Array of base class pointers
    Account* accounts[3];
    accounts[0] = &savingsAcc;
    accounts[1] = &currentAcc;
    accounts[2] = &loanAcc;


    int choice;
    double amount;

    // Menu-driven program
    do {
        printLine();
        cout << "        Smart Bank Menu        " << endl;
        printLine();
        cout << " 1. Deposit (Savings Account)" << endl;
        cout << " 2. Withdraw (Savings Account)" << endl;
        cout << " 3. Deposit EMI (Loan Account)" << endl;
        cout << " 4. Apply Service Charge (Current Account)" << endl;
        cout << " 5. Display All Accounts (Polymorphism)" << endl;
        cout << " 6. Show Account Types (Polymorphism)" << endl;
        cout << " 7. Get Savings Account Balance" << endl;
        cout << " 8. Add Interest (Savings Account)" << endl;
        cout << " 9. Show Savings Transaction History" << endl;
        cout << "10. Show Current Transaction History" << endl;
        cout << "11. Interest Calculator (Simple)" << endl;
        cout << "12. Interest Calculator (Compound)" << endl;
        cout << "13. Exit" << endl;
        printLine();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                savingsAcc.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                savingsAcc.withdraw(amount);
                break;

            case 3:
                cout << "Enter EMI amount: ";
                cin >> amount;
                loanAcc.deposit(amount);
                break;

            case 4:
                cout << "Enter service charge amount: ";
                cin >> amount;
                currentAcc.applyServiceCharge(amount);
                break;

            case 5:
                cout << "\n--- All Accounts (via Polymorphism) ---" << endl;
                for (int i = 0; i < 3; i++) {
                    accounts[i]->display();
                    cout << endl;
                }
                break;

            case 6:
                cout << "\n--- Account Types (via Polymorphism) ---" << endl;
                for (int i = 0; i < 3; i++) {
                    accounts[i]->accountType();
                }
                break;

            case 7:
                cout << "Savings Account Balance: " << savingsAcc.getBalance() << endl;
                break;

            case 8:
                savingsAcc.calculateInterest();
                break;

            case 9:
                cout << "\n--- Savings Account Transactions ---" << endl;
                savingsAcc.showTransactions();
                break;

            case 10:
                cout << "\n--- Current Account Transactions ---" << endl;
                currentAcc.showTransactions();
                break;

            case 11: {
                double principal, rate;
                int years;
                cout << "Enter Principal : "; cin >> principal;
                cout << "Enter Rate %    : "; cin >> rate;
                cout << "Enter Years     : "; cin >> years;
                InterestCalculator::displaySimpleInterest(principal, rate, years);
                break;
            }

            case 12: {
                double principal, rate;
                int years;
                cout << "Enter Principal : "; cin >> principal;
                cout << "Enter Rate %    : "; cin >> rate;
                cout << "Enter Years     : "; cin >> years;
                InterestCalculator::displayCompoundInterest(principal, rate, years);
                break;
            }

            case 13:
                cout << "Thank you for using Smart Bank Pro. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please enter 1-13." << endl;
        }

    } while (choice != 13);

    return 0;
}
