#include "CountLetter.hpp"

CountLetter::CountLetter(std::string name, bool (*f)(char ch))
    : name(name)
    , f(f)
{

}

std::string CountLetter::GetName() {
    return name;
}

int CountLetter::Compute(std::string str) {
    int count = 0;
    for (char ch : str) {
        if (f(ch)) {
            count++;
        }
    }
    return count;
}
