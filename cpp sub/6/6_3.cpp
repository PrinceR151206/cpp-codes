#include <iostream>
using namespace std;

void mergeSortedArrays(int* arr1, int size1, int* arr2, int size2) {
    int* mergedArr = new int[size1 + size2];  // Dynamically allocate memory for merged array
    int i = 0, j = 0, k = 0;

    // Merge the two sorted arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1 if any
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2 if any
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }

    // Display the merged sorted array
    cout << "Merged Array: ";
    for (int i = 0; i < size1 + size2; ++i) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;

    delete[] mergedArr;  // Deallocate memory to prevent memory leak
}

int main() {
    int size1, size2;

    // Input the sizes of the two arrays
    cout << "Enter size of first array: ";
    cin >> size1;
    int* arr1 = new int[size1];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }

    // Input the sizes of the second array
    cout << "Enter size of second array: ";
    cin >> size2;
    int* arr2 = new int[size2];
    cout << "Enter elements of second array: ";
    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    // Merge and display the result
    mergeSortedArrays(arr1, size1, arr2, size2);

    // Clean up memory
    delete[] arr1;
    delete[] arr2;

    cout << "\nprince 24ce105\n";
    return 0;
}
