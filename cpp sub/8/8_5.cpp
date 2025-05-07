#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Directory {
private:
    // Map to store folder names and associated files
    map<string, vector<string>> folders;

public:
    // Function to create a new folder
    void createFolder(const string& folderName) {
        if (folders.find(folderName) == folders.end()) {
            folders[folderName] = {};  // Create an empty list of files for the folder
            cout << "Folder '" << folderName << "' created successfully.\n";
        } else {
            cout << "Folder '" << folderName << "' already exists.\n";
        }
    }

    // Function to add a file to a folder
    void addFileToFolder(const string& folderName, const string& fileName) {
        if (folders.find(folderName) != folders.end()) {
            folders[folderName].push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
        } else {
            cout << "Folder '" << folderName << "' does not exist.\n";
        }
    }

    // Function to display the directory structure
    void displayDirectory() {
        cout << "\nDirectory Structure:\n";
        for (auto& folder : folders) {
            cout << "Folder: " << folder.first << "\n";
            cout << "Files: ";
            for (const auto& file : folder.second) {
                cout << file << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Directory dir;

    // Example operations
    dir.createFolder("Documents");
    dir.addFileToFolder("Documents", "resume.docx");
    dir.addFileToFolder("Documents", "report.pdf");
    dir.createFolder("Photos");
    dir.addFileToFolder("Photos", "vacation.jpg");

    // Displaying the directory structure
    dir.displayDirectory();

    cout << "\nprince 24ce105\n";
    return 0;
}
