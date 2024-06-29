#include <iostream>

#include "Sentence.hpp"
#include "ComputeVowels.hpp"
#include "CountLetter.hpp"
#include "LongestWord.hpp"

int main() {
    Sentence s("Second POO test");
    (s += new ComputeVowels("Voc")) += new CountLetter("CountE", [](char ch) { return ch == 'e'; });
    s += new LongestWord("long");
    s.ListAll();
    std::cout << "=====================" << std::endl;
    s.RunAll();
    std::cout << "=====================" << std::endl;
    s.Run("CountE");

    return 0;
}
