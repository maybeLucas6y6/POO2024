#include "Student.h"

#include <cstring>

int compare_students_name(Student* a, Student* b) {
    for (int i = 0; i <= strlen(a->get_name()) && i <= strlen(b->get_name()); i++) {
        if (a->get_name()[i] > b->get_name()[i]) {
            return 1;
        }
        else if (a->get_name()[i] < b->get_name()[i]) {
            return -1;
        }
    }
    return 0;
}
int compare_students_maths_grade(Student* a, Student* b) {
    if (a->get_maths_grade() > b->get_maths_grade()) {
        return 1;
    }
    else if (a->get_maths_grade() < b->get_maths_grade()) {
        return -1;
    }
    return 0;
}
int compare_students_english_grade(Student* a, Student* b) {
    if (a->get_english_grade() > b->get_english_grade()) {
        return 1;
    }
    else if (a->get_english_grade() < b->get_english_grade()) {
        return -1;
    }
    return 0;
}
int compare_students_history_grade(Student* a, Student* b) {
    if (a->get_history_grade() > b->get_history_grade()) {
        return 1;
    }
    else if (a->get_history_grade() < b->get_history_grade()) {
        return -1;
    }
    return 0;
}
int compare_students_average_grade(Student* a, Student* b) {
    if (a->get_average_grade() > b->get_average_grade()) {
        return 1;
    }
    else if (a->get_average_grade() < b->get_average_grade()) {
        return -1;
    }
    return 0;
}
