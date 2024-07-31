#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "contact_manager.h"

void displayMenu();
std::vector<Contact> loadContacts();
void saveContacts(const std::vector<Contact>& contacts);
void addContact(std::vector<Contact>& contacts);
void updateContact(std::vector<Contact>& contacts);
void deleteContact(std::vector<Contact>& contacts);
void listContacts(const std::vector<Contact>& contacts);
void searchContact(const std::vector<Contact>& contacts);

#endif
