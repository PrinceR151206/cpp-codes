#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload - operator
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload >> operator for input
    friend istream &operator>>(istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    sum = c1 + c2;
    diff = c1 - c2;

    cout << "\nSum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    cout << "\nprince 24ce105\n";
    return 0;
}
