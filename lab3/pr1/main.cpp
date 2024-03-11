#include "Math.h"
#include <iostream>

int main() {
    std::cout << Math::Add(69, 420) << "\n";
    std::cout << Math::Add(69, 420, 3) << "\n";
    std::cout << Math::Add(69.0, 420.0) << "\n";
    std::cout << Math::Add(69.0, 420.0, 3.0) << "\n";
    std::cout << Math::Mul(69, 420) << "\n";
    std::cout << Math::Mul(69, 420, 3) << "\n";
    std::cout << Math::Mul(69.0, 420.0) << "\n";
    std::cout << Math::Mul(69.0, 420.0, 3.0) << "\n";

    std::cout << Math::Add(5, 1, 2, 3, 4, 5) << "\n";

    auto p = Math::Add("76456789764578", "87345678908765434567");
    std::cout << p << "\n";
    //87345678908765434567
    //      76456789764578
    //87345755365555199145
    delete[] p;

    return 0;
}
