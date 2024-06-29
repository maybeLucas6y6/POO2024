#include "ComputeVowels.hpp"

ComputeVowels::ComputeVowels(std::string name)
    : name(name)
{

}

std::string ComputeVowels::GetName() {
    return name;
}

int ComputeVowels::Compute(std::string str) {
    int count = 0;
    std::string vowels = "aeiouAEIOU";
    for (char ch : str) {
        if (vowels.find(ch) != std::string::npos) {
            count++;
        }
    }
    return count;
}
