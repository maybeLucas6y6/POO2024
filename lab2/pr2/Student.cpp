#include "Student.h"

#include <cstring>

void my_strcpy(char* dest, const char* src) {
    for(int i = 0; src[i] != 0; i++) {
        dest[i] = src[i];
    }
}

const char* Student::get_name() {
    return this->name;
}
void Student::set_name(const char* str) {
    my_strcpy(this->name, str);
}

float Student::get_maths_grade() {
    return this->maths_grade;
}
void Student::set_maths_grade(float grade) {
    if (grade >= 1 && grade <= 10) {
        this->maths_grade = grade;
    }
}
float Student::get_english_grade() {
    return this->english_grade;
}
void Student::set_english_grade(float grade) {
    if (grade >= 1 && grade <= 10) {
        this->english_grade = grade;
    }
}
float Student::get_history_grade() {
    return this->history_grade;
}
void Student::set_history_grade(float grade) {
    if (grade >= 1 && grade <= 10) {
        this->history_grade = grade;
    }
}

float Student::get_average_grade() {
    return (this->maths_grade + this->english_grade + this->history_grade) / 3.0f;
}
