#include <iostream>
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius {
    float temp;

public:
    Celsius() : temp(0.0) {}
    Celsius(float t) : temp(t) {}

    // Conversion from Fahrenheit to Celsius
    Celsius(const Fahrenheit &f);

    float getTemp() const {
        return temp;
    }

    // Overload == operator
    bool operator==(const Celsius &c) {
        return temp == c.temp;
    }

    void input() {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
    }

    void display() {
        cout << temp << "°C";
    }
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit() : temp(0.0) {}
    Fahrenheit(float t) : temp(t) {}

    // Conversion from Celsius to Fahrenheit
    Fahrenheit(const Celsius &c) {
        temp = (c.getTemp() * 9.0 / 5.0) + 32;
    }

    float getTemp() const {
        return temp;
    }

    // Overload == operator
    bool operator==(const Fahrenheit &f) {
        return temp == f.temp;
    }

    void input() {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
    }

    void display() {
        cout << temp << "°F";
    }
};

// Celsius constructor implementation (after Fahrenheit is defined)
Celsius::Celsius(const Fahrenheit &f) {
    temp = (f.getTemp() - 32) * 5.0 / 9.0;
}

int main() {
    Celsius c;
    Fahrenheit f;

    c.input();
    f = Fahrenheit(c); // Convert Celsius to Fahrenheit

    cout << "\nConverted to Fahrenheit: ";
    f.display();

    f.input();
    c = Celsius(f); // Convert Fahrenheit to Celsius

    cout << "\nConverted to Celsius: ";
    c.display();

    cout << "\nprince 24ce105\n";
    return 0;
}
