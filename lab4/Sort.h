#pragma once

#include <initializer_list>

class Sort {
    int* data;
    int size;
    void SortPartition(int st, int dr, bool ascendent);
public:
    Sort(int count, int min_val, int max_val);
    Sort(std::initializer_list<int> list);
    Sort(int count, int* data);
    Sort(int count, ...);
    Sort(const char* str);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

