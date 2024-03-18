#include "Sort.h"

int main() {
    Sort random(10, 0, 100);
    random.BubbleSort();
    random.Print();

    Sort initlist = { 1, 2, 3 };
    initlist.InsertSort();
    initlist.Print();

    int vec[] = { 1,2,3,4,5,6,77,8,9,10,11,12,13,14,15 };
    Sort vect(15, vec);
    vect.InsertSort(true);
    vect.Print();

    Sort variadic(5, 10, 12, 13, 14, 15);
    variadic.QuickSort();
    variadic.Print();

    Sort str("10,40,100,5,70");
    str.QuickSort(true);
    str.Print();

    return 0;
}
