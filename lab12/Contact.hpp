#pragma once 

enum class ContactType {
    None,
    Friend,
    Acquaintance,
    Collegue
};

#include <string>

class Contact {
protected:
    std::string name; 
    ContactType type;
public:
    Contact() {};
    Contact(const std::string& name, ContactType type)
        : name(name)
        , type(type)
    {

    }
    const std::string& get_name() {
        return name;
    }
};
