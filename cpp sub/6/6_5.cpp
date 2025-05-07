#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor\n";  // Ensures that derived class destructor is called
    }

    virtual void display() const {
        cout << "Base class object\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived Destructor\n";  // Proper cleanup of resources in derived class
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

    // Delete the object through base class pointer
    delete obj;  // Destructor of Derived will be called due to virtual destructor in Base

    cout << "\nprince 24ce105\n";
    return 0;
}
