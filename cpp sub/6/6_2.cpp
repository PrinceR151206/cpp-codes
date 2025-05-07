#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Constructor to initialize point
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Method to move the point by a specified offset
    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;  // Return the updated object for method chaining
    }

    // Display the coordinates of the point
    void display() const {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Create a Point object
    Point p(5, 10);
    p.display();

    // Move the point by chaining method calls
    p.move(3, -5).move(-2, 4).move(1, 1);
    p.display();

    cout << "\nprince 24ce105\n";
    return 0;
}
