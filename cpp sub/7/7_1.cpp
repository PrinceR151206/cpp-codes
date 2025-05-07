#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct Word {
    char* word;
    int count;
};

class WordFrequency {
private:
    Word* words;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        Word* newWords = new Word[capacity];
        for (int i = 0; i < size; ++i) {
            newWords[i] = words[i];
        }
        delete[] words;
        words = newWords;
    }

public:
    WordFrequency() : capacity(10), size(0) {
        words = new Word[capacity];
    }

    ~WordFrequency() {
        for (int i = 0; i < size; ++i) {
            delete[] words[i].word;
        }
        delete[] words;
    }

    void addWord(const char* newWord) {
        for (int i = 0; i < size; ++i) {
            if (strcasecmp(words[i].word, newWord) == 0) {
                words[i].count++;
                return;
            }
        }

        if (size == capacity) {
            resize();
        }

        words[size].word = new char[strlen(newWord) + 1];
        strcpy(words[size].word, newWord);
        words[size].count = 1;
        size++;
    }

    void printWordFrequency() {
        for (int i = 0; i < size; ++i) {
            cout << words[i].word << ": " << words[i].count << endl;
        }
    }
};

int main() {
    WordFrequency wf;
    char input[500];
    cout << "Enter a paragraph: ";
    cin.getline(input, 500);

    char* token = strtok(input, " ,.-\n");
    while (token) {
        // Convert token to lowercase
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        wf.addWord(token);
        token = strtok(nullptr, " ,.-\n");
    }

    wf.printWordFrequency();
    cout << "\nprince 24ce105\n";
    return 0;
}
