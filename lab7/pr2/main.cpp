#include "Vector.hpp"
#include "String.hpp"
#include <string>

void int_test() {
    Vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_front(1);
    vec.push_front(-1);
    vec.print();
    std::cout << "Popped back " << vec.pop_back() << "\n";
    vec.print();
    std::cout << "Popped front " << vec.pop_front() << "\n";
    vec.print();
    std::cout << "-------\n";
    vec.remove(2);
    vec.print();
    vec.insert(1, 9);
    vec.print();
    vec.sort([](const int& a, const int& b){ return a < b; });
    vec.print();
    std::cout << "3rd element: " << vec.get(2) << "\n";
    vec.set(0, 3);
    vec.set(1, 6);
    vec.print();
    std::cout << "First index of 9: " << vec.first_index_of(9, [](const int& a, const int& b){ return a == b; });
}

void string_test() {
    Vector<String> vec;
    vec.push_back("two");
    vec.push_back("three");
    // vec.push_back("four");
    // vec.push_front("one");
    // vec.push_front("minus-one");
    vec.print();
}

int main() {
    string_test();
    return 0;
}
