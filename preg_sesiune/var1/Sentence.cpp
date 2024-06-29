#include <iostream>

#include "Sentence.hpp"

Sentence::Sentence(std::string content)
    : content(content)
{

}

Sentence::~Sentence() {
    for (Processor* processor : processors) {
        delete processor;
    }
}

void Sentence::RunAll() {
    for (Processor* processor : processors) {
        std::cout << "Name:"
            << processor->GetName()
            << " => "
            << processor->Compute(content)
            << "\n";
    }
}

void Sentence::ListAll() {
    for (Processor* processor : processors) {
        std::cout << "Name:"
            << processor->GetName()
            << "\n";
    }
}

void Sentence::Run(std::string name) {
    for (Processor* processor : processors) {
        if (processor->GetName() == name) {
            std::cout << processor->Compute(content) << "\n";
            return;
        }
    }
    std::cout << "aoleu";
}

Sentence& Sentence::operator+=(Processor* processor) {
    processors.push_back(processor);
    return *this;
}
