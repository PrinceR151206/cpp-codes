#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Product {
private:
    string name;
    int quantity;
    double price;

public:
    Product() : name(""), quantity(0), price(0.0) {}

    void readProduct() {
        cout << "Enter product name: ";
        getline(cin, name);
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();  // To ignore the newline character left by cin
    }

    void displayProduct() const {
        cout << setw(20) << left << name
             << setw(10) << right << quantity
             << setw(10) << right << fixed << setprecision(2) << price
             << endl;
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    void saveToFile(ofstream &outFile) const {
        outFile << name << "\n" << quantity << "\n" << price << "\n";
    }

    bool matchesName(const string &searchName) const {
        return name == searchName;
    }
};

class Inventory {
private:
    string filename;

public:
    Inventory(string file) : filename(file) {}

    void addProduct() {
        Product product;
        product.readProduct();

        ofstream outFile(filename, ios::app);  // Open file in append mode
        if (!outFile) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        product.saveToFile(outFile);
        outFile.close();
    }

    void viewInventory() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error opening file for reading." << endl;
            return;
        }

        Product product;
        while (inFile) {
            string name;
            int quantity;
            double price;

            getline(inFile, name);
            if (name.empty()) continue;  // Skip empty lines
            inFile >> quantity;
            inFile >> price;
            inFile.ignore();  // To ignore the newline character

            cout << setw(20) << left << name
                 << setw(10) << right << quantity
                 << setw(10) << right << fixed << setprecision(2) << price
                 << endl;
        }
        inFile.close();
    }

    void searchProduct(const string &searchName) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error opening file for reading." << endl;
            return;
        }

        Product product;
        bool found = false;
        while (inFile) {
            string name;
            int quantity;
            double price;

            getline(inFile, name);
            if (name.empty()) continue;  // Skip empty lines
            inFile >> quantity;
            inFile >> price;
            inFile.ignore();  // To ignore the newline character

            if (product.matchesName(searchName)) {
                product.displayProduct();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Product not found." << endl;
        }

        inFile.close();
    }
};

int main() {
    Inventory inventory("inventory.txt");

    int choice;
    while (true) {
        cout << "\n1. Add Product\n2. View Inventory\n3. Search Product\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left by cin

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;
            case 2:
                inventory.viewInventory();
                break;
            case 3:
                {
                    string searchName;
                    cout << "Enter product name to search: ";
                    getline(cin, searchName);
                    inventory.searchProduct(searchName);
                }
                break;
            case 4:
                cout << "\nprince 24ce105\n";
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
