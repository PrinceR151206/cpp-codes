#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    int int1, int2, int3;
    float float1, float2;
    double double1, double2;

    cout << "Enter two integers: ";
    cin >> int1 >> int2;
    cout << "Sum (int + int): " << calc.add(int1, int2) << endl;

    cout << "Enter two floats: ";
    cin >> float1 >> float2;
    cout << "Sum (float + float): " << calc.add(float1, float2) << endl;

    cout << "Enter two doubles: ";
    cin >> double1 >> double2;
    cout << "Sum (double + double): " << calc.add(double1, double2) << endl;

    cout << "Enter three integers: ";
    cin >> int1 >> int2 >> int3;
    cout << "Sum (int + int + int): " << calc.add(int1, int2, int3) << endl;

    cout << "\nprince 24ce105\n";
    return 0;
}
