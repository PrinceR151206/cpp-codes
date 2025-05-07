#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    string employeeName;
    double basicSalary;
    double bonus;

public:
    // Default bonus value
    static constexpr double defaultBonus = 1000.0;

    // Constructor with default or customized bonus
    Employee(string name, double salary, double customBonus = defaultBonus) {
        employeeName = name;
        basicSalary = salary;
        bonus = customBonus;
    }

    // Inline function to calculate total salary
    inline double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    // Display employee details
    void displayEmployeeDetails() const {
        cout << "Employee Name      : " << employeeName << endl;
        cout << "Basic Salary       : $" << basicSalary << endl;
        cout << "Bonus              : $" << bonus << endl;
        cout << "Total Salary       : $" << calculateTotalSalary() << "\n" << endl;
    }
};

int main() {
    vector<Employee> employees;
    int choice;

    do {
        cout << "\n--- Payroll System ---\n";
        cout << "1. Add Employee (Default Bonus)\n";
        cout << "2. Add Employee (Customized Bonus)\n";
        cout << "3. Display All Employees\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double salary;
                cin.ignore();
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Basic Salary: ";
                cin >> salary;
                employees.emplace_back(name, salary);  // Default bonus
                cout << "Employee added with default bonus.\n";
                break;
            }

            case 2: {
                string name;
                double salary, bonus;
                cin.ignore();
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Basic Salary: ";
                cin >> salary;
                cout << "Enter Bonus Amount: ";
                cin >> bonus;
                employees.emplace_back(name, salary, bonus);  // Customized bonus
                cout << "Employee added with customized bonus.\n";
                break;
            }

            case 3:
                if (employees.empty()) {
                    cout << "No employee records available.\n";
                } else {
                    for (size_t i = 0; i < employees.size(); ++i) {
                        cout << "\nEmployee #" << i + 1 << " Details:\n";
                        employees[i].displayEmployeeDetails();
                    }
                }
                break;

            case 4:
                cout << "\nExiting Payroll System..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    
    cout << "\nprince 24ce105\n";

    return 0;
}
