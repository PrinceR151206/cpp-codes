#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure to store student name and score
struct Student {
    string name;
    int score;

    // Constructor for convenience
    Student(string n, int s) : name(n), score(s) {}
};

// Comparison function to sort students by score in descending order
bool compareScores(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<Student> students;  // Dynamic list of students

    cout << "Enter student names and scores:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;
        students.push_back(Student(name, score));  // Add student to the list
    }

    // Sort students by score in descending order
    sort(students.begin(), students.end(), compareScores);

    cout << "\nRanked Students (Highest to Lowest):\n";
    for (int i = 0; i < students.size(); ++i) {
        cout << "Rank " << i + 1 << ": " << students[i].name << " with score " << students[i].score << endl;
    }

    cout << "\nprince 24ce105\n";
    return 0;
}
