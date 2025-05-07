#include <iostream>
#include <string>
using namespace std;

// Base class FuelType
class FuelType {
protected:
    string fuel;
public:
    FuelType(string f = "Petrol") : fuel(f) {}
    void displayFuel() {
        cout << "Fuel Type: " << fuel << endl;
    }
};

// Base class Brand
class Brand {
protected:
    string brandName;
public:
    Brand(string b = "Toyota") : brandName(b) {}
    void displayBrand() {
        cout << "Brand: " << brandName << endl;
    }
};

// Derived class Car
class Car : public FuelType, public Brand {
public:
    Car(string fuelType, string brand) : FuelType(fuelType), Brand(brand) {}
    void displayCarDetails() {
        displayFuel();
        displayBrand();
    }
};

int main() {
    Car car("Diesel", "Ford");
    car.displayCarDetails();

    cout << "\nprince 24ce105\n";
    return 0;
}
