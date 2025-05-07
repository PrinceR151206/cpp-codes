#include <iostream>
using namespace std;

class Base {
public:
    // Virtual Destructor ensures proper cleanup when deleting derived objects through base class pointer
    virtual ~Base() {
        cout << "Base Destructor\n";
    }

    virtual void display() const {
        cout << "Base class object\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor\n";
    }

    ~Derived() {
        cout << "Derived Destructor\n";  // Cleanup resources specific to Derived class
    }

    void display() const override {
        cout << "Derived class object\n";
    }
};

int main() {
    // Create an object of Derived class
    Base* obj = new Derived();

    // Display object info
    obj->display();

    // Delete the object through base class pointer, which ensures derived class destructor is called
    delete obj;  // Without virtual destructor, Derived destructor wouldn't be called and would cause memory leaks.

    cout << "\nprince 24ce105\n";
    return 0;
}
