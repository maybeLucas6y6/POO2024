#pragma once

#include <cstddef>
#include <ostream>

class String {
    char* data;
    size_t size;
public:
    String();
    String(const char* str);
    String(const String& str);
    String(String&& str);
    ~String();
    friend std::ostream& operator<<(std::ostream& stream, const String& str);
    String& operator=(const String& other);
    String& operator=(String&& other);
};
