#include <iostream>
#include <string>
using namespace std;

// Abstract base class GradingSystem
class GradingSystem {
protected:
    double marks;
public:
    GradingSystem(double m = 0) : marks(m) {}
    virtual void computeGrade() = 0;  // Pure virtual function
};

// Derived class Undergraduate
class Undergraduate : public GradingSystem {
public:
    Undergraduate(double m) : GradingSystem(m) {}
    void computeGrade() override {
        if (marks >= 50) {
            cout << "Grade: Pass" << endl;
        } else {
            cout << "Grade: Fail" << endl;
        }
    }
};

// Derived class Postgraduate
class Postgraduate : public GradingSystem {
public:
    Postgraduate(double m) : GradingSystem(m) {}
    void computeGrade() override {
        if (marks >= 70) {
            cout << "Grade: Pass" << endl;
        } else {
            cout << "Grade: Fail" << endl;
        }
    }
};

int main() {
    Undergraduate undergrad(65);
    undergrad.computeGrade();

    Postgraduate postgrad(75);
    postgrad.computeGrade();

    cout << "\nprince 24ce105\n";
    return 0;
}
