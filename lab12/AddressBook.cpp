#include "AddressBook.hpp"

#include <iostream>

#include "Contact.hpp"
#include "Friend.hpp"

bool AddressBook::add(const Contact& contact) {
    try {
        contacts.push_back(contact);
        return true;
    }
    catch (...) {
        return false;
    }
}

bool AddressBook::search(const std::string& name, Contact& contact) {
    for (Contact& c : contacts) {
        if (c.get_name() == name) {
            contact = c;
            return true;
        }
    }
    return false;
}

std::vector<Friend> AddressBook::get_friends_list() {
    std::vector<Friend> friends;
    for (Contact& contact : contacts) {
        if (contact.get_type() == ContactType::Friend) {
            friends.push_back(contact);
        }
    }
}

void AddressBook::print() {
    for (Contact& contact : contacts) {
        std::cout << contact.get_name() << "\n";
    }
}
