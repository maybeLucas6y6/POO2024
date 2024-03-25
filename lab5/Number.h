#pragma once

class Number {
    int size, capacity;
    char* data;
    int base;

    void ToDecimal();
    void FromDecimal(int base);
    static int ToInt(char c);
    static char ToChar(int n);
    int GetIntValue();
public:
    Number(const char* value, int base);
    Number(int val);
    Number(const Number& num);
    Number(const Number&& num);
    ~Number();
    friend Number operator+(const Number& A, const Number& B);
    friend Number operator-(const Number& A, const Number& B);
    bool operator==(const Number& num);
    bool operator!=(const Number& num);
    bool operator<=(const Number& num);
    bool operator>=(const Number& num);
    bool operator<(const Number& num);
    bool operator>(const Number& num);
    char operator[](int i);
    void operator--();
    void operator--(int value);
    void operator+=(const Number& num);
    void operator=(const Number& num);
    void operator=(const char* str);
    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
};
