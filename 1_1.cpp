#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    std::string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& name, const std::string& accNumber, double initialBalance = 0.0) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount!" << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrew: $" << amount << std::endl;
        }
    }

    // Check balance
    void checkBalance() const {
        std::cout << "Current balance: $" << balance << std::endl;
    }

    // Show account info
    void displayAccountInfo() const {
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        checkBalance();
    }
};

// Example usage
int main() {
    BankAccount acc("John Doe", "1234567890", 1000.0);

    acc.displayAccountInfo();
    acc.deposit(500);
    acc.withdraw(200);
    acc.withdraw(1500);  // This should show an error
    acc.checkBalance();

    std::cout<<"prince 24ce105";

    return 0;
}
