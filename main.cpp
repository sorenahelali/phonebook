#include <algorithm>
#include <string>
#include <iostream>
/*#include <fstream>
#include <vector>
#include <cstdio>
*/
using namespace std;


struct PersonInfo {
    string name;
    string tellNumber;

};

int selectedOption;

 phoneBook[1000];

int number_of_Add = 0;


void displayMenu() {
    cout << "Please choose an option:" << endl;
    cout << "1 - Add new phone number" << endl;
    cout << "2 - Search by name" << endl;
    cout << "3 - Search by number" << endl;
    cout << "4 - Print all numbers" << endl;
    cout << "5 - Exit" << endl;
}


void addNewNumber() {
    string name;
    string cellPhone;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your phone number: ";
    cin >> cellPhone;

    phoneBook[number_of_Add].name = name;
    phoneBook[number_of_Add].tellNumber = cellPhone;

    number_of_Add++;
}

void printAll() {
    for (int i = 0; i < number_of_Add; i++) {
        cout << "Name: " << phoneBook[i].name << " | Tel: " << phoneBook[i].tellNumber << endl;
    }
}


void searchByName() {
    string search_word;
    cout << "Enter name to search: ";
    cin >> search_word;

    bool found = false;
    for (int i = 0; i < number_of_Add; i++) {
        if (phoneBook[i].name == search_word) {
            cout << "Found: Name: " << phoneBook[i].name << " | number: " << phoneBook[i].tellNumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found with this name." << endl;
    }
}

void searchByNumber() {
    string search_word_by_number;
    cout << "Enter number to search: ";
    cin >> search_word_by_number;

    bool ali = false;
    for (int i = 0; i < number_of_Add; i++) {
        if (phoneBook[i].tellNumber == search_word_by_number) {
            cout << "Found: Name: " << phoneBook[i].name << " | number: " << phoneBook[i].tellNumber << endl;

            ali = true;
        }
    }
    if (!ali) {
        cout << "No entries found with this name." << endl;
    }
}
// Function to search by number



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
        cin >> selectedOption;

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
        system("pause");
        system("cls");
    }
}
