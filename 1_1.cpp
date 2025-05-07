#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(string name, string accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Deposit function to add money to account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n";
        } else {
            cout << "Error: Deposit amount must be positive.\n";
        }
    }

    // Withdraw function to subtract money from account
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive.\n";
        } else if (amount > balance) {
            cout << "Error: Insufficient funds.\n";
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << "\n";
        }
    }

    // Function to display account balance
    void checkBalance() const {
        cout << "Account Balance: " << balance << "\n";
    }

    // Function to display account details
    void displayAccountDetails() const {
        cout << "\nAccount Holder: " << accountHolder
             << "\nAccount Number: " << accountNumber
             << "\nBalance: " << balance << "\n";
    }
};

int main() {
    // Create an account for a customer
    string name, accountNum;
    double initialBalance;

    cout << "Enter Account Holder's Name: ";
    getline(cin, name);

    cout << "Enter Account Number: ";
    getline(cin, accountNum);

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    BankAccount account(name, accountNum, initialBalance);

    int choice;
    do {
        // Menu options
        cout << "\nBanking System Menu:\n";
        cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. View Account Details\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            double depositAmount;
            cout << "Enter amount to deposit: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
        } else if (choice == 2) {
            double withdrawAmount;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
        } else if (choice == 3) {
            account.checkBalance();
        } else if (choice == 4) {
            account.displayAccountDetails();
        } else if (choice != 5) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    cout << "\nprince 24ce105\n";
    return 0;
}
