#include "Array.hpp"
#include "Array.cpp"
#include "ArrayIterator.cpp"
// todo: ce cct e asta

class MyComparator : public Compare {
public:
    int CompareElements(const void* e1, const void* e2) override {
        int a = *reinterpret_cast<int*>(const_cast<void*>(e1));
        int b = *reinterpret_cast<int*>(const_cast<void*>(e2));
        if (a < b) {
            return -1;
        }
        if (a > b) {
            return 1;
        }
        return 0;
    }
};

int main() {
    Array<int> arr1;
    arr1.Insert(0, 0);
    arr1.Insert(0, 1);
    arr1.Insert(0, 2);
    arr1.Insert(1, 3);
    arr1.Print();

    Array<int> arr2;
    arr2.Insert(0, 9);
    arr2.Insert(0, 10);
    arr2.Insert(0, 11);
    arr2.Print(); 

    arr1.Insert(1, arr2);
    arr1.Print();

    arr1.Delete(2);
    arr1.Print();

    arr2 = arr1;
    arr2.Print();

    auto cmp = [](const int& a, const int& b) {
        if (a < b) {
            return -1;
        }
        if (a > b) {
            return 1;
        }
        return 0;
    };
    MyComparator mycmp;
    //arr2.Sort();
    //arr2.Sort(cmp);
    arr2.Sort(&mycmp);
    arr2.Print();

    std::cout << "2 at " << arr2.BinarySearch(2) << '\n';
    std::cout << "4 at " << arr2.BinarySearch(4, cmp) << '\n';
    std::cout << "9 at " << arr2.BinarySearch(9, &mycmp) << '\n';

    std::cout << "2 at " << arr2.Find(2) << '\n';
    std::cout << "4 at " << arr2.Find(4, cmp) << '\n';
    std::cout << "9 at " << arr2.Find(9, &mycmp) << '\n';

    try {
        std::cout << "Accesing at index 1: " << arr2[1] << '\n';
        std::cout << "Accesing at index 9: " << arr2[9] << '\n';
        std::cout << "Accesing at index 3: " << arr2[3] << '\n';
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
