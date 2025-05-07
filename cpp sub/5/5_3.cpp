#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}

    Point(int x_val, int y_val) {
        x = x_val;
        y = y_val;
    }

    // Overload unary - operator
    Point operator-() {
        return Point(-x, -y);
    }

    // Overload + operator
    Point operator+(const Point &p) {
        return Point(x + p.x, y + p.y);
    }

    // Overload == operator
    bool operator==(const Point &p) {
        return x == p.x && y == p.y;
    }

    // Input and output methods
    void input() {
        cout << "Enter x and y coordinates: ";
        cin >> x >> y;
    }

    void display() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1, p2;
    cout << "Enter first point:\n";
    p1.input();

    cout << "Enter second point:\n";
    p2.input();

    Point sum = p1 + p2;
    Point neg = -p1;

    cout << "\nSum of points: ";
    sum.display();

    cout << "\nNegation of first point: ";
    neg.display();

    if (p1 == p2)
        cout << "\nPoints are equal.";
    else
        cout << "\nPoints are not equal.";

    cout << "\nprince 24ce105\n";
    return 0;
}
