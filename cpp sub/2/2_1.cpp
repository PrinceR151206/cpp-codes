#include <iostream>
#include <vector>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l = 0, double w = 0) {
        length = l;
        width = w;
    }

    // Set or update dimensions
    void setDimensions(double l, double w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            cout << "Length and width must be positive values.\n";
        }
    }

    // Calculate area
    double getArea() const {
        return length * width;
    }

    // Calculate perimeter
    double getPerimeter() const {
        return 2 * (length + width);
    }

    // Display dimensions and results
    void display() const {
        cout << "Length: " << length << ", Width: " << width
             << ", Area: " << getArea()
             << ", Perimeter: " << getPerimeter() << endl;
    }
};

int main() {
    vector<Rectangle> rectangles;
    int choice;

    do {
        cout << "\n--- Rectangle Management System ---\n";
        cout << "1. Add a new rectangle\n";
        cout << "2. Update a rectangle's dimensions\n";
        cout << "3. Display all rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double l, w;
                cout << "Enter length: ";
                cin >> l;
                cout << "Enter width: ";
                cin >> w;
                rectangles.emplace_back(l, w);
                cout << "Rectangle added.\n";
                break;
            }
            case 2: {
                int index;
                double l, w;
                cout << "Enter rectangle index to update (starting from 0): ";
                cin >> index;
                if (index >= 0 && index < rectangles.size()) {
                    cout << "Enter new length: ";
                    cin >> l;
                    cout << "Enter new width: ";
                    cin >> w;
                    rectangles[index].setDimensions(l, w);
                    cout << "Dimensions updated.\n";
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 3: {
                if (rectangles.empty()) {
                    cout << "No rectangles to display.\n";
                } else {
                    for (size_t i = 0; i < rectangles.size(); ++i) {
                        cout << "Rectangle #" << i << ": ";
                        rectangles[i].display();
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);
    cout<<"prince 24ce105";
    return 0;
}
