#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {
    string sentence;
    map<string, int> wordFrequency;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string word = "";
    for (char& ch : sentence) {
        if (isalpha(ch) || ch == '\'') {  // Check for alphabetic characters or apostrophes
            word += tolower(ch);  // Convert to lowercase for case-insensitive comparison
        } else {
            if (!word.empty()) {
                wordFrequency[word]++;  // Update frequency of the word
                word = "";  // Reset word for the next one
            }
        }
    }

    // Handle last word in sentence if there's no punctuation after it
    if (!word.empty()) {
        wordFrequency[word]++;
    }

    cout << "\nWord Frequency Distribution:\n";
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
