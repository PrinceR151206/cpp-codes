#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class Shape
class Shape {
protected:
    double radius;
public:
    Shape(double r = 0) : radius(r) {}
    virtual double area() = 0;  // Pure virtual function for area calculation
};

// Derived class Circle
class Circle : public Shape {
public:
    Circle(double r) : Shape(r) {}
    double area() override {
        return M_PI * radius * radius;  // Area of circle: π * r^2
    }
};

int main() {
    vector<Circle> circles;
    int n;
    cout << "Enter the number of circles: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double radius;
        cout << "Enter the radius of circle " << i + 1 << ": ";
        cin >> radius;
        circles.push_back(Circle(radius));
    }

    cout << "\nAreas of the circles:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Area of circle " << i + 1 << ": " << circles[i].area() << endl;
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
