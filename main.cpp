#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "contact_manager.h"

using namespace std;

void showMenu() {
    cout << "----------------------------------------\n";
    cout << "           Contact Management           \n";
    cout << "----------------------------------------\n";
    cout << "1. Add Contact\n";
    cout << "2. Update Contact\n";
    cout << "3. Delete Contact\n";
    cout << "4. List Contacts\n";
    cout << "5. Search Contact\n";
    cout << "6. Exit\n";
    cout << "----------------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    ContactManager manager;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                manager.addContact();
                break;
            case 2:
                manager.updateContact();
                break;
            case 3:
                manager.deleteContact();
                break;
            case 4:
                manager.listContacts();
                break;
            case 5:
                manager.searchContact();
                break;
            case 6:
                cout << "\033[1mThanks for using the Contact Management System!\033[0m\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
