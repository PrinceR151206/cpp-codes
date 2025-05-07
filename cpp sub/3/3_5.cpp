#include <iostream>
#include <string>
using namespace std;

// Function to calculate the super digit recursively
int superDigit(int n) {
    // Base case: If n has a single digit, return it
    if (n < 10) {
        return n;
    }
    
    // Sum the digits of the number and call recursively
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return superDigit(sum);
}

int main() {
    string n;
    int k;
    
    // Taking input from the user
    cout << "Enter the number (as a string): ";
    cin >> n;
    cout << "Enter the number of repetitions (k): ";
    cin >> k;
    
    // Calculate the sum of digits of the number n
    int sum = 0;
    for (char c : n) {
        sum += c - '0'; // Convert char to int and add to sum
    }
    
    // Multiply the sum by k to simulate the concatenation of n k times
    sum *= k;
    
    // Compute the super digit of the result
    int result = superDigit(sum);
    
    cout << "The super digit is: " << result << endl;
    cout << "\nprince 24ce105\n"; // Adding the final line
    return 0;
}
