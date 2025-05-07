#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    string productID;
    string name;
    int quantity;
    double price;

public:
    // Constructor
    Product(const string& id, const string& n, int q, double p)
        : productID(id), name(n), quantity(q), price(p) {}

    string getProductID() const { return productID; }

    void updateQuantity(int change) {
        quantity += change;
        if (quantity < 0) quantity = 0;
    }

    double getTotalValue() const {
        return quantity * price;
    }

    void displayProduct() const {
        cout << "ID: " << productID
             << ", Name: " << name
             << ", Quantity: " << quantity
             << ", Price: $" << price << endl;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct() {
        string id, name;
        int quantity;
        double price;

        cout << "Enter Product ID: ";
        cin >> id;
        cin.ignore(); // Clear newline
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price per Unit: ";
        cin >> price;

        products.emplace_back(id, name, quantity, price);
        cout << "Product added successfully.\n";
    }

    void updateProductQuantity() {
        string id;
        int change;

        cout << "Enter Product ID to update: ";
        cin >> id;
        cout << "Enter quantity change (positive to add, negative to sell): ";
        cin >> change;

        for (auto& product : products) {
            if (product.getProductID() == id) {
                product.updateQuantity(change);
                cout << "Quantity updated.\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    void displayAllProducts() const {
        cout << "\n--- Inventory List ---\n";
        for (const auto& product : products) {
            product.displayProduct();
        }
    }

    void calculateTotalInventoryValue() const {
        double totalValue = 0;
        for (const auto& product : products) {
            totalValue += product.getTotalValue();
        }
        cout << "Total Inventory Value: $" << totalValue << endl;
    }
};

int main() {
    Inventory storeInventory;
    int choice;

    do {
        cout << "\n--- Inventory Management Menu ---\n";
        cout << "1. Add New Product\n";
        cout << "2. Update Product Quantity\n";
        cout << "3. Display All Products\n";
        cout << "4. Calculate Total Inventory Value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                storeInventory.addProduct();
                break;
            case 2:
                storeInventory.updateProductQuantity();
                break;
            case 3:
                storeInventory.displayAllProducts();
                break;
            case 4:
                storeInventory.calculateTotalInventoryValue();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);
    cout<<"prince 24ce105";

    return 0;
}
