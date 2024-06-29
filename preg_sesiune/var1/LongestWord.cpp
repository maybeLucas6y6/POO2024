#include "LongestWord.hpp"

LongestWord::LongestWord(std::string name)
    : name(name)
{

}

std::string LongestWord::GetName() {
    return name;
}

int LongestWord::Compute(std::string str) {
    auto last_word = str.begin();
    long max_len = 0;
    for (auto it = str.begin(); it != str.end(); it++) {
        if (*it == ' ') {
            auto dif = it - last_word;
            if (dif > max_len) {
                max_len = dif;
            }
            last_word = it;
        }
    }
    auto dif = str.end() - last_word;
    if (dif > max_len) {
        max_len = dif;
        last_word = str.end();
    }
    return max_len;
}
