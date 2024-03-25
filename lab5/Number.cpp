#include "Number.h"

#include <cstring>
#include <iostream>

Number::Number(const char * value, int base)
    : size(strlen(value))
    , capacity(size + 1)
    , data(new char[capacity])
    , base(base)
{
    strcpy(this->data, value);
}
Number::Number(int val)
    : base(10)
    , size(0)
{
    int v = val;
    while (v) {
        this->size++;
        v /= 10;
    }
    capacity = size + 1;
    data = new char[capacity]{};
    int i = size - 1;
    while(i >= 0) {
        data[i] = ToChar(val % 10);
        i--;
        val /= 10;
    }
}
Number::Number(const Number& num)
    : size(num.size)
    , capacity(num.capacity)
    , data(new char[capacity])
    , base(num.base)
{
    std::cout << "-> c &\n";
    strcpy(this->data, num.data); 
}
Number::Number(const Number&& num)
    : size(num.size)
    , capacity(num.capacity)
    , data(num.data)
    , base(num.base)
{
    std::cout << "-> c &&\n";
}
Number::~Number() {
    if (this->data != nullptr) {
        delete[] this->data;
        this->data = nullptr;
    }
}
Number operator+(const Number& A, const Number& B) {
    int targetBase = std::max(A.base, B.base);

    Number D = A;
    if (D.base != targetBase) {
        D.SwitchBase(targetBase);
    }
    int i = D.size - 1;

    Number C = B;
    if (C.base != targetBase) {
        C.SwitchBase(targetBase);
    }
    int j = C.size - 1;

    char* buf = new char[std::max(i, j) + 2]{};
    int idx = 0;
    int carry = 0;

    while (i >= 0 && j >= 0) {
        int x = Number::ToInt(D.data[i]) + Number::ToInt(C.data[j]) + carry;
        carry = x / targetBase;
        buf[idx] = Number::ToChar(x % targetBase);
        i--;
        j--;
        idx++;
    }

    while(i >= 0) {
        int x = Number::ToInt(D.data[i]) + carry;
        carry = x / targetBase;
        buf[idx] = Number::ToChar(x);
        i--;
        idx++;
    }
    while(j >= 0) {
        int x = Number::ToInt(C.data[j]) + carry;
        carry = x / targetBase;
        buf[idx] = Number::ToChar(x);
        j--;
        idx++;
    }

    if (carry == 1) {
        buf[idx] = Number::ToChar(carry);
        idx++;
    }

    i = 0;
    j = idx - 1;
    while (i < j) {
        std::swap(buf[i], buf[j]);
        i++;
        j--;
    }

    return { buf, targetBase };
}
Number operator-(const Number& A, const Number& B) {
    int targetBase = std::max(A.base, B.base);

    Number D = A;
    if (D.base != targetBase) {
        D.SwitchBase(targetBase);
    }
    int i = D.size - 1;

    Number C = B;
    if (C.base != targetBase) {
        C.SwitchBase(targetBase);
    }
    int j = C.size - 1;

    char* buf = new char[std::max(i, j) + 2]{};
    int idx = 0;
    int carry = 0;

    while (i >= 0 && j >= 0) {
        int x = Number::ToInt(D.data[i]) - Number::ToInt(C.data[j]) - carry;
        carry = x / targetBase;
        buf[idx] = Number::ToChar(x % targetBase);
        i--;
        j--;
        idx++;
    }

    while(i >= 0) {
        int x = Number::ToInt(D.data[i]) - carry;
        carry = x / targetBase;
        buf[idx] = Number::ToChar(x);
        i--;
        idx++;
    }
    while(j >= 0) {
        int x = Number::ToInt(C.data[j]) - carry;
        carry = x / targetBase;
        buf[idx] = Number::ToChar(x);
        j--;
        idx++;
    }

    if (carry == 1) {
        // bruh
        return { "", 0 };
    }

    i = 0;
    j = idx - 1;
    while (i < j) {
        std::swap(buf[i], buf[j]);
        i++;
        j--;
    }

    return { buf, targetBase };
}
bool Number::operator==(const Number& num) {
    Number A = *this, B = num;
    A.SwitchBase(10);
    B.SwitchBase(10);
    return A.GetIntValue() == B.GetIntValue();
}
bool Number::operator!=(const Number& num) {
    Number A = *this, B = num;
    A.SwitchBase(10);
    B.SwitchBase(10);
    return A.GetIntValue() != B.GetIntValue();
}
bool Number::operator<=(const Number& num) {
    Number A = *this, B = num;
    A.SwitchBase(10);
    B.SwitchBase(10);
    return A.GetIntValue() <= B.GetIntValue();
}
bool Number::operator>=(const Number& num) {
    Number A = *this, B = num;
    A.SwitchBase(10);
    B.SwitchBase(10);
    return A.GetIntValue() >= B.GetIntValue();
}
bool Number::operator<(const Number& num) {
    Number A = *this, B = num;
    A.SwitchBase(10);
    B.SwitchBase(10);
    return A.GetIntValue() < B.GetIntValue();
}
bool Number::operator>(const Number& num) {
    Number A = *this, B = num;
    A.SwitchBase(10);
    B.SwitchBase(10);
    return A.GetIntValue() > B.GetIntValue();
}
char Number::operator[](int i) {
    if (i > 0 && i < this->size) {
        return this->data[i];
    }

    return -1;
}
void Number::operator--() {
    for (int i = 0; i < this->size; i++) {
        this->data[i] = this->data[i + 1];
    }
}
void Number::operator--(int value) {
    this->size--;
    this->data[this->size - 1] = 0;
}
void Number::operator+=(const Number& num) {
    *this = *this + num;
}
void Number::operator=(const Number& num) {
    std::cout << "-> = &\n";
    this->size = num.size;
    this->capacity = num.capacity;
    this->base = num.base;
    delete[] this->data;
    this->data = new char[this->capacity];
    strcpy(this->data, num.data);
}
void Number::operator=(Number&& num) {
    std::cout << "-> = &&\n";
    this->size = num.size;
    this->capacity = num.capacity;
    this->base = num.base;
    delete[] this->data;
    num.data = nullptr;
}
void Number::operator=(const char* str) {
    if (this->data != nullptr) {
        delete[] data;
    }

    this->data = new char[strlen(str) + 1];
    strcpy(this->data, str);
    this->size = strlen(str);
    this->capacity = this->size + 1;
    this->base = 10;
}
void Number::SwitchBase(int newBase) {
    if (this->base != 10) {
        ToDecimal();
    }
    FromDecimal(newBase);
}
int Number::ToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return 10 + (c - 'a');
    }
    return -1;
}
char Number::ToChar(int n) {
    if (n >= 0 && n <= 9) {
        return '0' + n;
    }
    if (n >= 10 && n <= 15) {
        return 'a' + (n - 10);
    }
    return -1;
}
int Number::GetIntValue() {
    if (this->base != 10) {
        return 0;
    }

    int dec = 0;
    for (int i = 0; i < this->size; i++) {
        dec = dec * 10 + (this->data[i] - '0');
    }
    return dec;
}
void Number::ToDecimal() {
    char* buf = new char[this->size * 2]{};

    int power = 1;
    int num = 0;

    for (int i = this->size - 1; i >= 0; i--) {
        num += this->ToInt(this->data[i]) * power;
        power = power * this->base;
    }
 
    int i = 0;
    while (num > 0) {
        buf[i] = this->ToChar(num % 10);
        num /= 10;
        i++;
    }

    i--;
    int j = 0;
    while (j < i) {
        std::swap(buf[j], buf[i]);
        i--;
        j++;
    }

    if (this->size < strlen(buf)) {
        delete[] this->data;
        this->data = new char[strlen(buf) + 1]{};
        strcpy(this->data, buf);
        this->size = strlen(this->data);
        this->capacity = this->size + 1;
    }
    else {
        strcpy(this->data, buf);
        this->size = strlen(this->data);
        this->capacity = this->size + 1;
        delete[] buf;
    }
    this->base = 10;
}
void Number::FromDecimal(int newBase) {
    char* buf = new char[this->size * 16]{};

    int dec = 0;
    for (int i = 0; i < this->size; i++) {
        dec = dec * 10 + (this->data[i] - '0');
    }

    int i = 0;
    while (dec > 0) {
        buf[i] = this->ToChar(dec % newBase);
        i++;
        dec /= newBase;
    }

    i--;
    int j = 0;
    while (j < i) {
        std::swap(buf[j], buf[i]);
        i--;
        j++;
    }

    if (this->size < strlen(buf)) {
        //delete[] this->data;
        this->data = new char[strlen(buf) + 1]{};
        strcpy(this->data, buf);
        this->size = strlen(this->data);
        this->capacity = this->size + 1;
    }
    else {
        strcpy(this->data, buf);
        this->size = strlen(this->data);
        this->capacity = this->size + 1;
        delete[] buf;
    }
    this->base = newBase;
}
void Number::Print() {
    std::cout << "Base: " << this->base << " | ";
    std::cout << "Value: " << this->data << " | ";
    std::cout << "(" << this->size << "/" << this->capacity << ")\n";
}
int Number::GetDigitsCount() {
    return this->size;
}
int Number::GetBase() {
    return this->base;
}
