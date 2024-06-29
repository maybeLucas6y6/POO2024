#pragma once

#include "Procesator.h"

class AverageMath : public Procesator {
public:
    void Run(Student* student, int count) override;
    std::string GetName() override;
};
