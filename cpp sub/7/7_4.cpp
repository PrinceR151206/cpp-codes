#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;
    char grade;

public:
    Student() : name(""), marks(0), grade('F') {}

    void readStudent() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter marks: ";
        cin >> marks;
        cin.ignore();  // Ignore the newline character left by cin
        if (marks >= 90) grade = 'A';
        else if (marks >= 75) grade = 'B';
        else if (marks >= 50) grade = 'C';
        else grade = 'F';
    }

    void displayStudent() const {
        cout << setw(20) << left << name
             << setw(10) << right << marks
             << setw(10) << right << grade
             << endl;
    }

    void saveToFile(ofstream &outFile) const {
        outFile << name << "\n" << marks << "\n" << grade << "\n";
    }
};

class ReportCard {
private:
    string filename;

public:
    ReportCard(string file) : filename(file) {}

    void addStudent() {
        Student student;
        student.readStudent();

        ofstream outFile(filename, ios::app);  // Open file in append mode
        if (!outFile) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        student.saveToFile(outFile);
        outFile.close();
    }

    void generateReport() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error opening file for reading." << endl;
            return;
        }

        cout << setw(20) << left << "Student Name"
             << setw(10) << right << "Marks"
             << setw(10) << right << "Grade"
             << endl;
        cout << "----------------------------------------" << endl;

        Student student;
        while (inFile) {
            string name;
            int marks;
            char grade;

            getline(inFile, name);
            if (name.empty()) continue;  // Skip empty lines
            inFile >> marks;
            inFile >> grade;
            inFile.ignore();  // To ignore the newline character

            cout << setw(20) << left << name
                 << setw(10) << right << marks
                 << setw(10) << right << grade
                 << endl;
        }
        inFile.close();
    }

    void displayErrorHandling() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error: The file could not be opened." << endl;
        }
    }
};

int main() {
    ReportCard report("student_report.txt");

    int choice;
    while (true) {
        cout << "\n1. Add Student\n2. Generate Report\n3. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left by cin

        switch (choice) {
            case 1:
                report.addStudent();
                break;
            case 2:
                report.generateReport();
                break;
            case 3:
                cout << "\nprince 24ce105\n";
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
