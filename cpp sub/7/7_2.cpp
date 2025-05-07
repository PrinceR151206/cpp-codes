#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

class FileAnalyzer {
private:
    int totalLines;
    int totalWords;
    int totalChars;

public:
    FileAnalyzer() : totalLines(0), totalWords(0), totalChars(0) {}

    bool processFile(const char* filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Could not open file." << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            totalLines++;
            totalChars += line.length();

            // Count words
            bool inWord = false;
            for (char ch : line) {
                if (isalnum(ch)) {
                    if (!inWord) {
                        inWord = true;
                        totalWords++;
                    }
                } else {
                    inWord = false;
                }
            }
        }
        file.close();
        return true;
    }

    void displayStats() const {
        cout << "Total lines: " << totalLines << endl;
        cout << "Total words: " << totalWords << endl;
        cout << "Total characters: " << totalChars << endl;
    }
};

int main() {
    FileAnalyzer analyzer;
    const char* filename = "sample.txt";  // Modify the file name as needed

    if (analyzer.processFile(filename)) {
        analyzer.displayStats();
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
