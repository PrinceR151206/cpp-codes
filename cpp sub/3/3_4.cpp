#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse

using namespace std;

// Template function to find the maximum value in a collection
template <typename T>
T findMax(const vector<T>& collection) {
    T maxVal = collection[0];
    for (const T& item : collection) {
        if (item > maxVal) {
            maxVal = item;
        }
    }
    return maxVal;
}

// Template function to reverse a collection
template <typename T>
void reverseCollection(vector<T>& collection) {
    reverse(collection.begin(), collection.end());
}

// Template function to display a collection
template <typename T>
void displayCollection(const vector<T>& collection) {
    for (const T& item : collection) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    int size;
    
    // Ask user to choose the type of collection to work with
    cout << "Choose the data type for the collection:\n";
    cout << "1. Integers\n2. Floats\n3. Characters\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the number of integers: ";
        cin >> size;
        vector<int> collection(size);
        cout << "Enter the integers: ";
        for (int i = 0; i < size; ++i) {
            cin >> collection[i];
        }

        // Operations
        cout << "Maximum value: " << findMax(collection) << endl;
        reverseCollection(collection);
        cout << "Reversed collection: ";
        displayCollection(collection);
    }
    else if (choice == 2) {
        cout << "Enter the number of floats: ";
        cin >> size;
        vector<float> collection(size);
        cout << "Enter the floats: ";
        for (int i = 0; i < size; ++i) {
            cin >> collection[i];
        }

        // Operations
        cout << "Maximum value: " << findMax(collection) << endl;
        reverseCollection(collection);
        cout << "Reversed collection: ";
        displayCollection(collection);
    }
    else if (choice == 3) {
        cout << "Enter the number of characters: ";
        cin >> size;
        vector<char> collection(size);
        cout << "Enter the characters: ";
        for (int i = 0; i < size; ++i) {
            cin >> collection[i];
        }

        // Operations
        cout << "Maximum value: " << findMax(collection) << endl;
        reverseCollection(collection);
        cout << "Reversed collection: ";
        displayCollection(collection);
    }
    else {
        cout << "Invalid choice!\n";
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
