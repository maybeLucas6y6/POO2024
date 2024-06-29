#include <iostream>

#include "Students.h"

Students::Students(std::initializer_list<Student> students)
    : students(students)
{

}

Students::~Students() {
    for (auto proc : procs) {
        delete proc;
    }
}

Students& Students::operator+=(Procesator* procesator) {
    procs.push_back(procesator);
    return *this;
}

void Students::print_all() {
    for (auto student : students) {
        std::cout << student.name << " Math: " << student.mate << " Rom: " << student.romana << std::endl;
    }
}

void Students::analyze(std::string proc_name) {
    for (auto procesator : procs) {
        if (procesator->GetName() == proc_name) {
            std::cout << procesator->GetName() << " = ";
            procesator->Run(students.data(), students.size());
        }
    }
}
