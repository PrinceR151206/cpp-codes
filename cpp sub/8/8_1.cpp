#include <iostream>
#include <vector>
#include <algorithm>  // for std::reverse
using namespace std;

int main() {
    vector<int> numbers;
    int n, num;

    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    cout << "Enter the sequence of integers: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    // Approach 1: Using std::reverse
    reverse(numbers.begin(), numbers.end());
    cout << "\nReversed sequence using std::reverse: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }

    // Approach 2: Reversing manually using iterators
    cout << "\nReversed sequence manually using iterators: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << " ";
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
