#pragma once

#include "Processor.hpp"

class CountLetter : public Processor {
    std::string name;
    bool (*f)(char ch);
public:
    CountLetter(std::string name, bool (*f)(char ch));
    std::string GetName() override;
    int Compute(std::string str) override;
};
