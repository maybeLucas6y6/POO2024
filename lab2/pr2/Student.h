#pragma once

class Student {
    char name[256]{0};
    float maths_grade = 0.0f;
    float english_grade = 0.0f;
    float history_grade = 0.0f;
public:
    const char* get_name();
    void set_name(const char* str);

    float get_maths_grade();
    void set_maths_grade(float grade);
    float get_english_grade();
    void set_english_grade(float grade);
    float get_history_grade();
    void set_history_grade(float grade);

    float get_average_grade();
};
