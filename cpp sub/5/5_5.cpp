#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float Area() = 0; // Pure virtual function
};

class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float Area() {
        return length * width;
    }
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) : radius(r) {}

    float Area() {
        return 3.14159f * radius * radius;
    }
};

int main() {
    int choice;
    Shape* shape = nullptr;

    cout << "Choose Shape:\n1. Rectangle\n2. Circle\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        float l, w;
        cout << "Enter length and width: ";
        cin >> l >> w;
        shape = new Rectangle(l, w);
    } else if (choice == 2) {
        float r;
        cout << "Enter radius: ";
        cin >> r;
        shape = new Circle(r);
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }

    cout << "Area = " << shape->Area() << endl;
    delete shape;

    cout << "\nprince 24ce105\n";
    return 0;
}
