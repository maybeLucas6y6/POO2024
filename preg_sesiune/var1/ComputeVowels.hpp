#pragma once

#include "Processor.hpp"

class ComputeVowels : public Processor {
    std::string name;
public:
    ComputeVowels(std::string name);
    std::string GetName() override;
    int Compute(std::string str) override;
};
