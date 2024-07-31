#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "1. Add Contact" << endl;
    cout << "2. Update Contact" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. List Contacts" << endl;
    cout << "5. Search Contact" << endl;
    cout << "6. Exit" << std::endl;
    cout << "Enter your choice: ";
}

vector<Contact> loadContacts() {
    vector<Contact> contacts;
    ifstream infile("contacts.txt");
    string line, name, phone;
    
    while (getline(infile, line)) {
        istringstream iss(line);
        getline(iss, name, ':');
        getline(iss, name);
        getline(iss, phone, ':');
        getline(iss, phone);
        contacts.push_back(Contact(name, phone));
    }
    
    return contacts;
}

void saveContacts(const vector<Contact>& contacts) {
    ofstream outfile("contacts.txt");
    
    for (const auto& contact : contacts) {
        outfile << "name: " << contact.name << "\n";
        outfile << "phone: " << contact.phone << "\n\n";
    }
}

void addContact(vector<Contact>& contacts) {
    string name, phone;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phone);
    contacts.push_back(Contact(name, phone));
    cout << "Contact added successfully." << endl;
}

void updateContact(vector<Contact>& contacts) {
    string name, newName, newPhone;
    cout << "Enter the name of the contact to update: ";
    getline(cin, name);
    
    for (auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Enter new name: ";
            getline(cin, newName);
            cout << "Enter new phone number: ";
            getline(cin, newPhone);
            contact.name = newName;
            contact.phone = newPhone;
            cout << "Contact updated successfully." << endl;
            return;
        }
    }
    
    cout << "Contact not found." << endl;
}

void deleteContact(vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to delete: ";
    getline(cin, name);
    
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            cout << "User has been deleted successfully." << endl;
            return;
        }
    }
    
    cout << "Contact not found." << endl;
}

void listContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts found." << endl;
        return;
    }
    
    for (const auto& contact : contacts) {
        cout << "Name: " << contact.name << ", Phone: " << contact.phone << endl;
    }
}

void searchContact(const vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to search: ";
    getline(cin, name);
    
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Name: " << contact.name << ", Phone: " << contact.phone << std::endl;
            return;
        }
    }
    
    cout << "Contact not found." << endl;
}
