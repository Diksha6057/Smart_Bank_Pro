#include <iostream>
#include <string>

using namespace std;


class Account {
private:
    int accountNumber;
    double balance;

public:
    
    Account(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }

    
    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

   
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};

bool transferFunds(Account& sender, Account& receiver, double amount) {
    
    if (amount <= 0) {
        cout << "Error: Transfer amount is 0!" << endl;
        return false;
    }

  ो
    if (sender.withdraw(amount)) {
       ो
        receiver.deposit(amount);
        
        cout << "\n Transfer Successful!" << endl;
        cout << "Account " << sender.getAccountNumber() 
             << " se Account " << receiver.getAccountNumber() 
             << " mein $" << amount << " transfer Done." << endl;
        return true;
    } else {
        
        cout << "\n Transfer Failed! Account " 
             << sender.getAccountNumber() << " Low Balance." << endl;
        return false;
    }
}


int main() {
   
    Account user1(1001, 5000.0); 
    Account user2(1002, 2000.0); 

    cout << "--- Transfer ---" << endl;
    cout << "User 1 Balance: $" << user1.getBalance() << endl;
    cout << "User 2 Balance: $" << user2.getBalance() << endl;

    
    transferFunds(user1, user2, 1500.0);

    cout << "\n--- Transfer---" << endl;
    cout << "User 1 Balance: $" << user1.getBalance() << endl;
    cout << "User 2 Balance: $" << user2.getBalance() << endl;

 
    transferFunds(user2, user1, 50000.0);

    return 0;
}
