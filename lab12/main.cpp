#include <iostream>

#include "AddressBook.hpp"
#include "Friend.hpp"
#include "Acquaintance.hpp"
#include "Collegue.hpp"

int main() {
    AddressBook ab;
    ab.add((Friend){"F1", ContactType::Friend, "6 Mai 2004", "0712345678", "Pacurari"});
    ab.add((Friend){"F2", ContactType::Friend, "6 Mai 2004", "0712345678", "Pacurari"});
    ab.add((Friend){"F3", ContactType::Friend, "6 Mai 2004", "0712345678", "Pacurari"});
    ab.add((Acquaintance){"A1", ContactType::Acquaintance, "777"});
    ab.add((Acquaintance){"A2", ContactType::Acquaintance, "777"});
    ab.add((Collegue){"C1", ContactType::Collegue, "112", "Bitdefender", "Sf. Lazar"});
    ab.add((Collegue){"C2", ContactType::Collegue, "112", "Bitdefender", "Sf. Lazar"});
    ab.add((Collegue){"C3", ContactType::Collegue, "112", "Bitdefender", "Sf. Lazar"});
    ab.add((Collegue){"C4", ContactType::Collegue, "112", "Bitdefender", "Sf. Lazar"});
    ab.print();

    Friend a("F1", ContactType::Friend, "6 Mai 2004", "0712345678", "Pacurari");
    Acquaintance b("A1", ContactType::Acquaintance, "777");
    Collegue c("C3", ContactType::Collegue, "112", "Bitdefender", "Sf. Lazar");
    std::cout << a << b << c;

    if (Contact d; ab.search("F2", d)) {
        std::cout << "Found " << d.get_name() << "\n";
    }
    else {
        std::cout << "Not found\n";
    }

    return 0;
}
