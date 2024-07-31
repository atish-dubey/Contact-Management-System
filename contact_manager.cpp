#include "contact_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

ContactManager::ContactManager() {
    loadContacts();
}

void ContactManager::loadContacts() {
    contacts.clear();
    ifstream file("contacts.txt");
    string line, name, phone;

    while (getline(file, line)) {
        istringstream iss(line);
        getline(iss, name, ',');
        getline(iss, phone);
        if (!name.empty() && !phone.empty()) {
            contacts.push_back(Contact(name, phone));
        }
    }
}

void ContactManager::saveContacts() {
    ofstream file("contacts.txt");
    for (const auto& contact : contacts) {
        file << "name: " << contact.name << ", phone: " << contact.phone << "\n";
    }
}

void ContactManager::addContact() {
    string name, phone;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone: ";
    getline(cin, phone);
    contacts.push_back(Contact(name, phone));
    saveContacts();
    cout << "Contact added successfully!\n";
}

void ContactManager::updateContact() {
    string name;
    cout << "Enter the name of the contact to update: ";
    getline(cin, name);
    
    auto it = find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        return contact.name == name;
    });
    
    if (it != contacts.end()) {
        cout << "Enter new phone: ";
        getline(cin, it->phone);
        saveContacts();
        cout << "Contact updated successfully!\n";
    } else {
        cout << "Contact not found!\n";
    }
}

void ContactManager::deleteContact() {
    string name;
    cout << "Enter the name of the contact to delete: ";
    getline(cin, name);
    
    auto it = remove_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        return contact.name == name;
    });
    
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        saveContacts();
        cout << "\033[1mContact deleted successfully!\033[0m\n";
    } else {
        cout << "Contact not found!\n";
    }
}

void ContactManager::listContacts() {
    cout << left << setw(20) << "Name" << "Phone" << "\n";
    cout << "----------------------------------------\n";
    for (const auto& contact : contacts) {
        cout << left << setw(20) << contact.name << contact.phone << "\n";
    }
    cout << "----------------------------------------\n";
}

void ContactManager::searchContact() {
    string name;
    cout << "Enter the name of the contact to search: ";
    getline(cin, name);
    
    auto it = find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        return contact.name == name;
    });
    
    if (it != contacts.end()) {
        cout << "Name: " << it->name << "\n";
        cout << "Phone: " << it->phone << "\n";
    } else {
        cout << "Contact not found!\n";
    }
}
