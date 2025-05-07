#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Default constructor (zero initial balance)
    BankAccount() {
        accountHolder = "Default Customer";
        accountNumber = "000000";
        balance = 0.0;
    }

    // Parameterized constructor
    BankAccount(string name, string number, double initialBalance) {
        accountHolder = name;
        accountNumber = number;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient funds! Withdrawal failed.\n";
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully.\n";
        }
    }

    // Display account details
    void displayAccount() const {
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n--- Digital Banking System ---\n";
        cout << "1. Create Account (Default)\n";
        cout << "2. Create Account (With Details)\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                accounts.emplace_back();
                cout << "Default account created.\n";
                break;

            case 2: {
                string name, number;
                double initialBalance;
                cin.ignore();
                cout << "Enter Account Holder Name: ";
                getline(cin, name);
                cout << "Enter Account Number: ";
                getline(cin, number);
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;
                accounts.emplace_back(name, number, initialBalance);
                cout << "Account created with provided details.\n";
                break;
            }

            case 3: {
                int index;
                double amount;
                cout << "Enter account index (starting from 0): ";
                cin >> index;
                if (index >= 0 && index < accounts.size()) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[index].deposit(amount);
                } else {
                    cout << "Invalid account index.\n";
                }
                break;
            }

            case 4: {
                int index;
                double amount;
                cout << "Enter account index (starting from 0): ";
                cin >> index;
                if (index >= 0 && index < accounts.size()) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[index].withdraw(amount);
                } else {
                    cout << "Invalid account index.\n";
                }
                break;
            }

            case 5:
                if (accounts.empty()) {
                    cout << "No accounts available.\n";
                } else {
                    for (size_t i = 0; i < accounts.size(); ++i) {
                        cout << "\nAccount #" << i << ":\n";
                        accounts[i].displayAccount();
                    }
                }
                break;

            case 6:
                cout << "\nSystem shutting down..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    // Signature
    cout << "\nprince 24ce105\n";

    return 0;
}
