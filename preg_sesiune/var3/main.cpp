#include <iostream>

class B {

};

class A : virtual public B {
public:
    int f(int, int x) {
        return x;
    }
};

int main() {
    A a;
    std::cout << a.f(6, 9);
    return 0;
}
