#pragma once

#include "Processor.hpp"

class LongestWord : public Processor {
    std::string name;
public:
    LongestWord(std::string name);
    std::string GetName() override;
    int Compute(std::string str) override;
};
