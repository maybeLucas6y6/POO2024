#pragma once

#include <vector>
#include <string>

class Contact;
class Friend;

class AddressBook {
    std::vector<Contact> contacts;
public:
    bool search(const std::string& name, Contact& contact);
    std::vector<Friend> get_friends_list();
    bool erase(const std::string& name);
    bool add(const Contact& contact);

    void print();
};
