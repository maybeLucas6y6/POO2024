#pragma once

#include <vector>
#include <string>

#include "Procesator.h"

struct Student {
    std::string name;
    int mate, romana;
};

class Students {
    std::vector<Student> students;
    std::vector<Procesator*> procs;
public:
    Students(std::initializer_list<Student> students);
    ~Students();
    Students& operator+=(Procesator* procesator);
    void print_all();
    void analyze(std::string proc_name);
};
