#include <iostream>

#include "BestRomana.h"
#include "Students.h"

void BestRomana::Run(Student* student, int count) {
    int best_grade = student->romana;
    std::string best_name = student->name;
    for (int i = 1; i < count; i++) {
        if (student->romana > best_grade) {
            best_grade = student->romana;
            best_name = student->name;
        }
        //student = reinterpret_cast<Student*>(reinterpret_cast<char*>(student) + sizeof(Student));
        student++;
    }
    std::cout << best_name << " with grade: " << best_grade << std::endl;
}

std::string BestRomana::GetName() {
    return "BestRomana";
}
