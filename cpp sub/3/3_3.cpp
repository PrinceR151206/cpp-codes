#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    static int totalAccounts; // Static variable to track total accounts

    // Constructor to initialize account details
    Account(string name, int accNumber, double initialBalance = 0) {
        accountHolder = name;
        accountNumber = accNumber;
        balance = initialBalance;
        totalAccounts++; // Increment total accounts whenever a new account is created
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else if (amount > balance) {
            cout << "Insufficient balance for withdrawal.\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    // Method to transfer money to another account
    void transfer(Account &toAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            toAccount.balance += amount;
            cout << "Transferred " << amount << " to account " << toAccount.accountNumber << "\n";
        } else if (amount > balance) {
            cout << "Insufficient balance for transfer.\n";
        } else {
            cout << "Invalid transfer amount.\n";
        }
    }

    // Method to display account details
    void displayAccount() const {
        cout << "\nAccount Holder: " << accountHolder << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }

    // Static method to get total number of accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Getter for account number to compare user input
    int getAccountNumber() const {
        return accountNumber;
    }
};

// Initialize static member variable
int Account::totalAccounts = 0;

int main() {
    vector<Account> accounts; // Vector to store all accounts
    int choice;
    string name;
    int accountNumber;
    double amount;
    int numAccounts;

    cout << "Enter the number of accounts you want to create: ";
    cin >> numAccounts;

    for (int i = 0; i < numAccounts; ++i) {
        cout << "\nEnter account details for account " << i + 1 << ":\n";
        cout << "Account Holder Name: ";
        cin.ignore(); // To ignore the newline character left by previous input
        getline(cin, name);
        cout << "Account Number: ";
        cin >> accountNumber;
        cout << "Initial Balance: ";
        cin >> amount;
        
        // Create a new account and add to the accounts vector
        Account newAccount(name, accountNumber, amount);
        accounts.push_back(newAccount);
    }

    do {
        cout << "\nBanking Menu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Transfer Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Display Total Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int accNum;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter deposit amount: ";
            cin >> amount;
            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!\n";
            break;
        }
        case 2: {
            int accNum;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!\n";
            break;
        }
        case 3: {
            int fromAccNum, toAccNum;
            cout << "Enter source account number: ";
            cin >> fromAccNum;
            cout << "Enter destination account number: ";
            cin >> toAccNum;
            cout << "Enter transfer amount: ";
            cin >> amount;

            Account* fromAccount = nullptr;
            Account* toAccount = nullptr;

            // Find the source and destination accounts
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == fromAccNum) {
                    fromAccount = &acc;
                }
                if (acc.getAccountNumber() == toAccNum) {
                    toAccount = &acc;
                }
            }

            if (fromAccount && toAccount) {
                fromAccount->transfer(*toAccount, amount);
            } else {
                cout << "One or both account numbers are invalid.\n";
            }
            break;
        }
        case 4: {
            int accNum;
            cout << "Enter account number to display: ";
            cin >> accNum;
            bool found = false;
            for (const auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.displayAccount();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!\n";
            break;
        }
        case 5:
            cout << "Total accounts created: " << Account::getTotalAccounts() << "\n";
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    cout << "\nprince 24ce105\n";
    return 0;
}
