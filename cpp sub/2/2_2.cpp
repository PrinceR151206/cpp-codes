#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string rollNumber;
    string name;
    float marks[3];

public:
    // Default constructor
    Student() {
        rollNumber = "0000";
        name = "Default Student";
        marks[0] = marks[1] = marks[2] = 0.0f;
    }

    // Parameterized constructor
    Student(string r, string n, float m1, float m2, float m3) {
        rollNumber = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // Calculate average marks
    float calculateAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0f;
    }

    // Display student details
    void displayDetails() const {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name      : " << name << endl;
        cout << "Marks     : " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average   : " << calculateAverage() << "\n" << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student (Default)\n";
        cout << "2. Add Student (With Input)\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                students.emplace_back(); // default constructor
                cout << "Default student added.\n";
                break;

            case 2: {
                string roll, name;
                float m1, m2, m3;
                cout << "Enter Roll Number: ";
                cin >> roll;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Marks in 3 Subjects: ";
                cin >> m1 >> m2 >> m3;
                students.emplace_back(roll, name, m1, m2, m3);
                cout << "Student added with provided details.\n";
                break;
            }

            case 3:
                if (students.empty()) {
                    cout << "No student records available.\n";
                } else {
                    cout << "\n--- Student Records ---\n";
                    for (const auto& student : students) {
                        student.displayDetails();
                    }
                }
                break;

            case 4:
                cout << "\nExiting system..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    cout << "\nprince 24ce105\n";

    return 0;
}
