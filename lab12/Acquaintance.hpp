#pragma once

#include <iostream>

#include "Contact.hpp"

class Acquaintance : public Contact {
    std::string phone_number;
public:
    Acquaintance() = delete;
    Acquaintance(const std::string& name,
            ContactType type,
            const std::string& phone_number)
        : Contact(name, type)
        , phone_number(phone_number)
    {

    }
    friend std::ostream& operator<<(std::ostream& stream, const Acquaintance& fr) {
        stream << fr.name << " ";
        switch (fr.type) {
            case ContactType::Friend: stream << "friend "; break;
            case ContactType::Acquaintance: stream << "acquaintance "; break;
            case ContactType::Collegue: stream << "collegue "; break;
            default: break;
        }
        stream << fr.phone_number << " ";
        stream << "\n";
        return stream;
    }
};
