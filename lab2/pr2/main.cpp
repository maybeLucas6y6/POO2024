#include "Student.h"
#include "Func.h"

#include <iostream>

int main() {
    Student a, b;

    a.set_name("abc");
    b.set_name("abd");

    a.set_maths_grade(10.0f);
    a.set_english_grade(10.0f);
    a.set_history_grade(10.0f);

    b.set_maths_grade(9.0f);
    b.set_english_grade(2.0f);
    b.set_history_grade(6.0f);

    std::cout << compare_students_name(&a, &b);
    return 0;
}
