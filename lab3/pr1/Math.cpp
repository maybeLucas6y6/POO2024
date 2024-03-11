#include <cstdarg>
#include <cstring>
#include <algorithm>
#include "Math.h"

int Math::Add(int x, int y) {
    return x + y;
}
int Math::Add(int x, int y, int z) {
    return x + y + z;
}
double Math::Add(double x, double y) {
    return x + y;
}
double Math::Add(double x, double y, double z) {
    return x + y + z;
}
int Math::Mul(int x, int y) {
    return x * y;
}
int Math::Mul(int x, int y, int z) {
    return x * y * z;
}
double Math::Mul(double x, double y) {
    return x * y;
}
double Math::Mul(double x, double y, double z) {
    return x * y * z;
}
int Math::Add(int count, ...) {
    va_list args;

    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
char* Math::Add(const char* x, const char* y) {
    if (x == nullptr || y == nullptr) {
        return nullptr;
    }

    auto xlen = strlen(x), ylen = strlen(y);
    char* buf = new char[std::max(xlen, ylen) + 2];
    int i = 1;
    bool carry = false;
    while (i <= xlen && i <= ylen) {
        char res = (x[xlen - i] - '0') + (y[ylen - i] - '0') + carry;
        carry = res / 10;
        res = res % 10;
        buf[i - 1] = res + '0';
        i++;
    }

    while (i <= xlen) {
        char res = (x[xlen - i] - '0') + carry;
        carry = res / 10;
        res = res % 10;
        buf[i - 1] = res + '0';
        i++;
    }
    while (i <= ylen) {
        char res = (y[ylen - i] - '0') + carry;
        carry = res / 10;
        res = res % 10;
        buf[i - 1] = res + '0';
        i++;
    }
    
    buf[i - 1] = (carry ? '1' : 0);
    buf[i] = 0;
    for (i = 0; i < strlen(buf) / 2; i++) {
        std::swap(buf[i], buf[strlen(buf) - 1 - i]);
    }
    return buf;
}
