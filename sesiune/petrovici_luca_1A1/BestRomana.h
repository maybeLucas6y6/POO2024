#pragma once

#include "Procesator.h"

class BestRomana : public Procesator {
public:
    void Run(Student* student, int count) override;
    std::string GetName() override;
};
