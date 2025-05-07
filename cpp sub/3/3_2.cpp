#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

using namespace std;

// Recursive function to compute the sum of the array elements
int recursiveSum(const vector<int>& arr, int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + recursiveSum(arr, n - 1); // Recursive call
}

// Iterative function to compute the sum of the array elements
int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;  // Sum using a loop
    }
    return sum;
}

int main() {
    int n;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> n;

    // Create a vector to hold the array elements
    vector<int> arr(n);

    // Input the elements of the array
    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Measure execution time for the recursive sum calculation
    auto start = chrono::high_resolution_clock::now();
    int recursiveResult = recursiveSum(arr, n);
    auto end = chrono::high_resolution_clock::now();
    auto recursiveDuration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nRecursive sum: " << recursiveResult << endl;
    cout << "Recursive execution time: " << recursiveDuration.count() << " microseconds\n";

    // Measure execution time for the iterative sum calculation
    start = chrono::high_resolution_clock::now();
    int iterativeResult = iterativeSum(arr);
    end = chrono::high_resolution_clock::now();
    auto iterativeDuration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nIterative sum: " << iterativeResult << endl;
    cout << "Iterative execution time: " << iterativeDuration.count() << " microseconds\n";

    // Compare results to ensure correctness
    if (recursiveResult == iterativeResult) {
        cout << "\nBoth methods produced the same result.\n";
    } else {
        cout << "\nThe methods produced different results!\n";
    }

    cout << "\nprince 24ce105\n";

    return 0;
}
