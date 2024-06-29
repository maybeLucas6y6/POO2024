#pragma once

#include <iostream>

#include "Contact.hpp"

class Friend : public Contact {
    std::string date_of_birth;
    std::string phone_number;
    std::string address;
public:
    Friend() = delete;
    Friend(const std::string& name,
            ContactType type,
            const std::string& date_of_birth,
            const std::string& phone_number,
            const std::string& address)
        : Contact(name, type)
        , date_of_birth(date_of_birth)
        , phone_number(phone_number)
        , address(address)
    {

    }
    friend std::ostream& operator<<(std::ostream& stream, const Friend& fr) {
        stream << fr.name << " ";
        switch (fr.type) {
            case ContactType::Friend: stream << "friend "; break;
            case ContactType::Acquaintance: stream << "acquaintance "; break;
            case ContactType::Collegue: stream << "collegue "; break;
            default: break;
        }
        stream << fr.date_of_birth << " ";
        stream << fr.phone_number << " ";
        stream << fr.address << " ";
        stream << "\n";
        return stream;
    }
};
