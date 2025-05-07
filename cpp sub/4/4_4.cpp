#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class BankAccount
class BankAccount {
protected:
    string accountNumber;
    double balance;
public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void displayAccount() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
    virtual void deposit(double amount) {
        balance += amount;
    }
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

// Derived class SavingsAccount
class SavingsAccount : public BankAccount {
protected:
    double interestRate;
public:
    SavingsAccount(string accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}
    void displayAccount() override {
        BankAccount::displayAccount();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class CurrentAccount
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;
public:
    CurrentAccount(string accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}
    void displayAccount() override {
        BankAccount::displayAccount();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings("S12345", 1000.0, 5.0);
    savings.deposit(200);
    savings.withdraw(500);
    savings.displayAccount();

    CurrentAccount current("C12345", 2000.0, 500.0);
    current.deposit(500);
    current.withdraw(3000);
    current.displayAccount();

    cout << "\nprince 24ce105\n";
    return 0;
}
