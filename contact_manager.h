#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
    Contact() = default;
    Contact(const string &name, const string &phone) : name(name), phone(phone) {}
};

class ContactManager {
public:
    ContactManager();
    void addContact();
    void updateContact();
    void deleteContact();
    void listContacts();
    void searchContact();
private:
    vector<Contact> contacts;
    void loadContacts();
    void saveContacts();
};

#endif
