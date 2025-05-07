#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class Employee
class Employee : public Person {
protected:
    string employeeId;
public:
    Employee(string n, int a, string id) : Person(n, a), employeeId(id) {}
    void display() override {
        Person::display();
        cout << "Employee ID: " << employeeId << endl;
    }
};

// Derived class Manager
class Manager : public Employee {
private:
    string department;
public:
    Manager(string n, int a, string id, string dep) : Employee(n, a, id), department(dep) {}
    void display() override {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager manager("John Doe", 40, "E123", "Sales");
    manager.display();

    cout << "\nprince 24ce105\n";
    return 0;
}
