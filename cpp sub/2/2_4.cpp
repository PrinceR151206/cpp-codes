#include <iostream>
#include <vector>
#include <string>

using namespace std;

class InventoryItem {
private:
    string itemID;
    string itemName;
    double price;
    int quantity;

public:
    // Default constructor
    InventoryItem() {
        itemID = "0000";
        itemName = "Unnamed Item";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    InventoryItem(string id, string name, double p, int q) {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    // Add stock
    void addStock(int amount) {
        if (amount > 0) {
            quantity += amount;
            cout << "Stock increased by " << amount << " units.\n";
        } else {
            cout << "Invalid stock amount.\n";
        }
    }

    // Sell item
    void sellItem(int amount) {
        if (amount <= 0) {
            cout << "Invalid sale quantity.\n";
        } else if (amount > quantity) {
            cout << "Not enough stock to sell " << amount << " units!\n";
        } else {
            quantity -= amount;
            cout << "Sold " << amount << " units successfully.\n";
        }
    }

    // Display item details
    void display() const {
        cout << "Item ID   : " << itemID << endl;
        cout << "Name      : " << itemName << endl;
        cout << "Price     : $" << price << endl;
        cout << "Quantity  : " << quantity << " units" << endl;
        cout << "Stock Value: $" << price * quantity << "\n" << endl;
    }
};

int main() {
    vector<InventoryItem> items;
    int choice;

    do {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item (Default)\n";
        cout << "2. Add Item (With Details)\n";
        cout << "3. Add Stock to Item\n";
        cout << "4. Sell Item\n";
        cout << "5. Display All Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                items.emplace_back();
                cout << "Default item added.\n";
                break;

            case 2: {
                string id, name;
                double price;
                int quantity;
                cin.ignore();
                cout << "Enter Item ID: ";
                getline(cin, id);
                cout << "Enter Item Name: ";
                getline(cin, name);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Starting Quantity: ";
                cin >> quantity;
                items.emplace_back(id, name, price, quantity);
                cout << "Item added with provided details.\n";
                break;
            }

            case 3: {
                int index, amount;
                cout << "Enter item index to add stock (starting from 0): ";
                cin >> index;
                if (index >= 0 && index < items.size()) {
                    cout << "Enter quantity to add: ";
                    cin >> amount;
                    items[index].addStock(amount);
                } else {
                    cout << "Invalid item index.\n";
                }
                break;
            }

            case 4: {
                int index, amount;
                cout << "Enter item index to sell (starting from 0): ";
                cin >> index;
                if (index >= 0 && index < items.size()) {
                    cout << "Enter quantity to sell: ";
                    cin >> amount;
                    items[index].sellItem(amount);
                } else {
                    cout << "Invalid item index.\n";
                }
                break;
            }

            case 5:
                if (items.empty()) {
                    cout << "No items in inventory.\n";
                } else {
                    for (size_t i = 0; i < items.size(); ++i) {
                        cout << "\nItem #" << i << ":\n";
                        items[i].display();
                    }
                }
                break;

            case 6:
                cout << "\nExiting Inventory System..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    // Signature output
    cout << "\nprince 24ce105\n";

    return 0;
}
