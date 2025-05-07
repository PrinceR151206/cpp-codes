#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    // Resize the array if it exceeds current capacity
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    // Constructor
    DynamicArray() : size(0), capacity(2) {
        arr = new int[capacity];
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // Add element at the end
    void addElement(int element) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = element;
    }

    // Remove element at a specific index
    void removeElement(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        } else {
            cout << "Invalid index.\n";
        }
    }

    // Display the array elements
    void display() const {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;

    // Add some elements
    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);
    arr.addElement(40);
    arr.display();

    // Remove an element
    arr.removeElement(2);  // Remove element at index 2
    arr.display();

    cout << "\nprince 24ce105\n";
    return 0;
}
