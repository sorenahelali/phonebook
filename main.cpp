#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct PersonInfo {
    string name;
    string tellNumber;
};

int selectedOption;
vector<PersonInfo> phoneBook; // Use vector for flexibility

// Display the menu
void displayMenu() {
    cout << "Please choose an option:" << endl;
    cout << "1 - Add new phone number" << endl;
    cout << "2 - Search by name" << endl;
    cout << "3 - Search by number" << endl;
    cout << "4 - Print all numbers" << endl;
    cout << "5 - Exit" << endl;
}

// Add a new number
void addNewNumber() {
    string name;
    string cellPhone;

    cout << "Please enter your name: ";
    // Read name with spaces
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Please enter your phone number: ";
    getline(cin, cellPhone);

    phoneBook.push_back({name, cellPhone});
}

// Print all numbers
void printAll() {
    if (phoneBook.empty()) {
        cout << "Phone book is empty." << endl;
        return;
    }

    for (size_t i = 0; i < phoneBook.size(); ++i) {
        cout << "Name: " << phoneBook[i].name << " | Tel: " << phoneBook[i].tellNumber << endl;
    }
}

// Search by name
void searchByName() {
    string search_word;
    cout << "Enter name to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, search_word);

    bool found = false;
    for (size_t i = 0; i < phoneBook.size(); ++i) {
        if (phoneBook[i].name == search_word) {
            cout << "Found: Name: " << phoneBook[i].name << " | number: " << phoneBook[i].tellNumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found with this name." << endl;
    }
}

// Search by number
void searchByNumber() {
    string search_number;
    cout << "Enter number to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, search_number);

    bool found = false;
    for (size_t i = 0; i < phoneBook.size(); ++i) {
        if (phoneBook[i].tellNumber == search_number) {
            cout << "Found: Name: " << phoneBook[i].name << " | number: " << phoneBook[i].tellNumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found with this number." << endl;
    }
}

// Optional: clear screen (OS dependent)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    while (true) {
        displayMenu();
        if (!(cin >> selectedOption)) {
            // If input is not a number
            cout << "Invalid input. Exiting." << endl;
            break;
        }

        switch (selectedOption) {
            case 1:
                addNewNumber();
                break;
            case 2:
                searchByName();
                break;
            case 3:
                searchByNumber();
                break;
            case 4:
                printAll();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        // Optional pause/clear
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Uncomment if you want to use them
        // system("pause");
        // clearScreen();
    }
}