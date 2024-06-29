#pragma once

#include <iostream>

#include "Contact.hpp"

class Collegue : public Contact {
    std::string phone_number;
    std::string company;
    std::string work_address;
public:
    Collegue() = delete;
    Collegue(const std::string& name,
            ContactType type,
            const std::string& phone_number,
            const std::string& company,
            const std::string& work_address)
        : Contact(name, type)
        , phone_number(phone_number)
        , company(company)
        , work_address(work_address)
    {

    }
    friend std::ostream& operator<<(std::ostream& stream, const Collegue& fr) {
        stream << fr.name << " ";
        switch (fr.type) {
            case ContactType::Friend: stream << "friend "; break;
            case ContactType::Acquaintance: stream << "acquaintance "; break;
            case ContactType::Collegue: stream << "collegue "; break;
            default: break;
        }
        stream << fr.phone_number << " ";
        stream << fr.company << " ";
        stream << fr.work_address << " ";
        stream << "\n";
        return stream;
    }
};
