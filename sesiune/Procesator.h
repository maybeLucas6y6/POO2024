#pragma once

#include <string>

struct Student;

class Procesator {
public:
    virtual void Run(Student* student, int count) = 0;
    virtual std::string GetName() = 0;
    virtual ~Procesator() = default;
};
