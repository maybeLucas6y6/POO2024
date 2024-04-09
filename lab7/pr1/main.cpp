#include <iostream>

float operator"" _Kelvin(long double x) {
    return x + 273.15f;
}

float operator"" _Fahrenheit(long double x) {
    return (x * 1.8f) + 32.0f;
}

int main() {
    float a = 2974.824_Kelvin;
    float b = 273.1287_Fahrenheit;

    std::cout << a << " " << b;
}
