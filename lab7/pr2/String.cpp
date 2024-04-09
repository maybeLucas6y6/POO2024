#include "String.hpp"

#include <cstring>

String::String()
    : data(nullptr)
{
    printf("default ctor: %p-%p-%s\n", this, data, data);
}
String::String(const char* str)
    : data(new char[strlen(str)])
{
    printf("string ctor: %p-%p <- %p-%s\n", this, this->data, str, str);
    strcpy(this->data, str);
}
String::String(const String& other) {
    printf("copy ctor: %p-%p-%s <- %p-%p-%s\n", this, this->data, this->data, &other, other.data, other.data);
    if (this->data != nullptr) {
        delete[] this->data;
        this->data = nullptr;
    }
    if (other.data != nullptr) {
        this->data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
    }
}
String::String(String&& other) {
    printf("move ctor: %p-%p-%s <- %p-%p-%s\n", this, this->data, this->data, &other, other.data, other.data);
    if (this->data != nullptr) {
        delete[] this->data;
        this->data = nullptr;
    }
    if (other.data != nullptr) {
        this->data = other.data;
        other.data = nullptr;
    }
}
String::~String() {
    printf("dtor: %p-%p-%s\n", this, this->data, (this->data == nullptr ? "" : this->data));
    if (this->data != nullptr) {
        delete[] this->data;
    }
}
std::ostream& operator<<(std::ostream& stream, const String& str) {
    stream << str.data;
    return stream;
}
String& String::operator=(const String& other) {
    printf("copy operator=: %p-%p-%s <- %p-%p-%s\n", this, this->data, this->data, &other, other.data, other.data);
    if (this->data != nullptr) {
        delete[] this->data;
        this->data = nullptr;
    }
    if (other.data != nullptr) {
        this->data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
    }
    return *this;
}
String& String::operator=(String&& other) {
    printf("move operator=: %p-%p-%s <- %p-%p-%s\n", this, this->data, this->data, &other, other.data, other.data);
    if (this->data != nullptr) {
        delete[] this->data;
        this->data = nullptr;
    }
    if (other.data != nullptr) {
        this->data = other.data;
        other.data = nullptr;
    }
    return *this;
}
