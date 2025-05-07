#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> uniqueTransactionIDs;  // Set to automatically handle duplicates

    cout << "Enter the transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        int transactionID;
        cin >> transactionID;
        uniqueTransactionIDs.insert(transactionID);  // Insert into set (duplicates are discarded)
    }

    cout << "\nUnique Transaction IDs in sorted order:\n";
    for (auto it = uniqueTransactionIDs.begin(); it != uniqueTransactionIDs.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
