#include <iostream>

#include "AverageMath.h"
#include "Students.h"

void AverageMath::Run(Student* student, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += student->mate; 
        student = reinterpret_cast<Student*>(reinterpret_cast<char*>(student) + sizeof(Student));
    }
    std::cout << sum / count << std::endl;
}

std::string AverageMath::GetName() {
    return "AverageMath";
}
