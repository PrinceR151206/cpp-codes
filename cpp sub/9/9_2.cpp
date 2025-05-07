#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    vector<string> transactionLog;

public:
    BankAccount(const string& name, double initialBalance)
        : accountHolder(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("Deposit amount must be positive.");
            cout << "Error: Deposit amount must be positive.\n";
        } else {
            balance += amount;
            logTransaction("Deposited " + to_string(amount));
            cout << "Deposited: " << amount << "\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("Withdrawal amount must be positive.");
            cout << "Error: Withdrawal amount must be positive.\n";
        } else if (amount > balance) {
            logTransaction("Insufficient funds for withdrawal.");
            cout << "Error: Insufficient funds for withdrawal.\n";
        } else {
            balance -= amount;
            logTransaction("Withdrew " + to_string(amount));
            cout << "Withdrew: " << amount << "\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    void logTransaction(const string& transaction) {
        transactionLog.push_back(transaction);
    }

    void displayTransactionLog() const {
        cout << "\nTransaction Log:\n";
        for (const auto& entry : transactionLog) {
            cout << entry << endl;
        }
    }
};

int main() {
    string name;
    double initialBalance;

    cout << "Enter account holder's name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    int choice;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Display Transaction Log\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            double depositAmount;
            cout << "Enter deposit amount: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
        } else if (choice == 2) {
            double withdrawAmount;
            cout << "Enter withdrawal amount: ";
            cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
        } else if (choice == 3) {
            cout << "Current balance: " << account.getBalance() << "\n";
        } else if (choice == 4) {
            account.displayTransactionLog();
        }

    } while (choice != 5);

    cout << "\nprince 24ce105\n";
    return 0;
}
