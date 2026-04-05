#include <iostream>
#include <string>
#include <exception>

using namespace std;

class LimitExceededException : public exception {
public:
    const char* what() const throw() {
        return "\n[ERROR] Transaction Failed: Account limit exceeded (Minimum Balance or Overdraft limit reached)!\n";
    }
};

class BaseAccount {
protected:
    int accountNumber;
    double balance;

public:
    BaseAccount(int acc, double bal) {
        accountNumber = acc;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n[SUCCESS] $" << amount << " deposited successfully.\n";
        } else {
            cout << "\n[ERROR] Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount) = 0; 

    double getBalance() { return balance; }
    int getAccountNumber() { return accountNumber; }
    
    virtual ~BaseAccount() {} 
};

class SavingsAccount : public BaseAccount {
private:
    double minBalance;

public:
    SavingsAccount(int acc, double bal, double minBal) : BaseAccount(acc, bal) {
        minBalance = minBal;
    }

    void withdraw(double amount) override {
        if (balance - amount < minBalance) {
            throw LimitExceededException();
        }
        balance -= amount;
        cout << "\n[SUCCESS] Withdrew $" << amount << " from Savings Account.\n";
    }
};

class CurrentAccount : public BaseAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(int acc, double bal, double limit) : BaseAccount(acc, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (balance - amount < -overdraftLimit) {
            throw LimitExceededException();
        }
        balance -= amount;
        cout << "\n[SUCCESS] Withdrew $" << amount << " from Current Account.\n";
    }
};

int main() {
    BaseAccount* myAccount = nullptr; 
    int choice;

    cout << "=========================================\n";
    cout << "       SMART BANKING PRO SYSTEM          \n";
    cout << "=========================================\n\n";

    cout << "--- Create Your Account ---\n";
    cout << "1. Savings Account\n";
    cout << "2. Current Account\n";
    cout << "Choose account type (1 or 2): ";
    
    int accType;
    cin >> accType;

    int accNo;
    double initialBal;
    
    cout << "Enter new Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Deposit Amount: $";
    cin >> initialBal;

    if (accType == 1) {
        double minBal;
        cout << "Enter Minimum Balance rule for this Savings A/c: $";
        cin >> minBal;
        myAccount = new SavingsAccount(accNo, initialBal, minBal); 
        cout << "\n[SUCCESS] Savings Account Created!\n";
    } 
    else if (accType == 2) {
        double odLimit;
        cout << "Enter Overdraft Limit for this Current A/c: $";
        cin >> odLimit;
        myAccount = new CurrentAccount(accNo, initialBal, odLimit);
        cout << "\n[SUCCESS] Current Account Created!\n";
    } 
    else {
        cout << "\n[ERROR] Invalid Selection. Exiting program...\n";
        return 1;
    }

    do {
        cout << "\n=========================================\n";
        cout << "   ACCOUNT DASHBOARD (A/c: " << myAccount->getAccountNumber() << ")";
        cout << "\n=========================================\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Funds\n";
        cout << "3. Withdraw Funds\n";
        cout << "4. Exit\n";
        cout << "Select an operation (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n-> Current Balance: $" << myAccount->getBalance() << "\n";
                break;

            case 2: {
                double depAmount;
                cout << "Enter amount to deposit: $";
                cin >> depAmount;
                myAccount->deposit(depAmount);
                break;
            }

            case 3: {
                double withAmount;
                cout << "Enter amount to withdraw: $";
                cin >> withAmount;
                
                try {
                    myAccount->withdraw(withAmount); 
                } 
                catch (const LimitExceededException& e) {
                    cout << e.what(); 
                }
                break;
            }

            case 4:
                cout << "\nThank you for using Smart Banking Pro. Goodbye!\n";
                break;

            default:
                cout << "\n[ERROR] Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    delete myAccount; 
    return 0;
}
