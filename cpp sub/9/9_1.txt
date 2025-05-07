#include <iostream>
#include <limits>  // For std::numeric_limits
using namespace std;

bool isValidInput(double& value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear(); // Clears error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input
        return false;
    }
    return true;
}

int main() {
    double loanAmount, annualIncome;

    cout << "Enter the total loan amount: ";
    while (!isValidInput(loanAmount)) {
        cout << "Invalid input! Please enter a valid number for the loan amount: ";
    }

    cout << "Enter the annual income: ";
    while (!isValidInput(annualIncome)) {
        cout << "Invalid input! Please enter a valid number for the annual income: ";
    }

    // Check for zero income to prevent division by zero
    if (annualIncome == 0) {
        cout << "Error: Annual income cannot be zero.\n";
    } else {
        double loanToIncomeRatio = loanAmount / annualIncome;
        cout << "Loan-to-Income Ratio: " << loanToIncomeRatio << endl;
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
