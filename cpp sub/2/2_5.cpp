#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Loan {
private:
    string loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate; // in percentage
    int tenureMonths;

public:
    // Default constructor
    Loan() {
        loanID = "L0000";
        applicantName = "Default Applicant";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 1; // To avoid division by zero in EMI
    }

    // Parameterized constructor
    Loan(string id, string name, double amount, double interest, int months) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = interest;
        tenureMonths = months;
    }

    // Calculate EMI using the standard formula
    double calculateEMI() const {
        double monthlyRate = (annualInterestRate / 12.0) / 100.0; // Convert to decimal
        double numerator = loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths);
        double denominator = pow(1 + monthlyRate, tenureMonths) - 1;
        return denominator == 0 ? 0.0 : numerator / denominator;
    }

    // Display loan details
    void display() const {
        cout << "Loan ID            : " << loanID << endl;
        cout << "Applicant Name     : " << applicantName << endl;
        cout << "Loan Amount        : $" << loanAmount << endl;
        cout << "Annual Interest    : " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure        : " << tenureMonths << " months" << endl;
        cout << "Calculated EMI     : $" << calculateEMI() << endl;
    }
};

int main() {
    vector<Loan> loans;
    int choice;

    do {
        cout << "\n--- Loan Management System ---\n";
        cout << "1. Add Loan (Default)\n";
        cout << "2. Add Loan (With Details)\n";
        cout << "3. Display All Loans\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                loans.emplace_back();
                cout << "Default loan added.\n";
                break;

            case 2: {
                string id, name;
                double amount, interest;
                int months;
                cin.ignore();
                cout << "Enter Loan ID: ";
                getline(cin, id);
                cout << "Enter Applicant Name: ";
                getline(cin, name);
                cout << "Enter Loan Amount: ";
                cin >> amount;
                cout << "Enter Annual Interest Rate (%): ";
                cin >> interest;
                cout << "Enter Loan Tenure (months): ";
                cin >> months;
                loans.emplace_back(id, name, amount, interest, months);
                cout << "Loan added with customer data.\n";
                break;
            }

            case 3:
                if (loans.empty()) {
                    cout << "No loan records available.\n";
                } else {
                    for (size_t i = 0; i < loans.size(); ++i) {
                        cout << "\nLoan #" << i << ":\n";
                        loans[i].display();
                    }
                }
                break;

            case 4:
                cout << "\nExiting Loan System..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    // Signature output
    cout << "\nprince 24ce105\n";

    return 0;
}
