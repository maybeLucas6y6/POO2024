#pragma once

#include <vector>

#include "Processor.hpp"

class Sentence {
    std::vector<Processor*> processors;
    std::string content;
public:
    Sentence(std::string content);
    ~Sentence();
    void RunAll();
    void ListAll();
    void Run(std::string name);
    Sentence& operator+=(Processor* processor);
};
