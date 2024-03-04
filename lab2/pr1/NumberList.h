#pragma once

class NumberList {
    int* numbers;
    int count;
    int capacity;
public:
    void Init(int capacity = 0);          // count will be 0
    void Add(int x);      // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector

    void Uninit();
};
