#include "Sort.h"
#include <random>
#include <ctime>
#include <cstring>
#include <cstdarg>

#include <iostream>

Sort::Sort(int count, int min_val, int max_val)
    : size(count)
    , data(new int[count])
{
    std::srand(time(0));
    for (int i = 0; i < this->size; i++) {
        this->data[i] = (std::rand() % (max_val - min_val + 1)) + min_val;
    }
}
Sort::Sort(std::initializer_list<int> list)
{
    this->size = list.size();
    this->data = new int[this->size];
    std::copy(list.begin(), list.end(), this->data);
}
Sort::Sort(int count, int* data)
    : size(count)
    , data(new int[count])
{
    memcpy(this->data, data, this->size * sizeof(int));
}
Sort::Sort(int count, ...)
    : size(count)
    , data(new int[count])
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < this->size; i++)
    {
         this->data[i] = va_arg(args, int);
    }
    va_end(args);
}
Sort::Sort(const char* str)
    : size(0)
{
    int num = 0;
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ',') {
            cnt++;
        } 
    }
    this->data = new int[cnt + 1];
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        }
        else {
            this->data[this->size] = num;
            this->size++;
            num = 0;
        }
    }
    this->data[this->size] = num;
    this->size++;
}
Sort::~Sort() {
    delete[] this->data;
}
void Sort::InsertSort(bool ascendent) {
    int temp, j;
    for (int i = 0; i < this->size; i++) {
        temp = this->data[i];
        j = i - 1;
        while (j >= 0 && ((this->data[j] < temp && !ascendent) || (this->data[j] > temp && ascendent))) {
            this->data[j + 1] = this->data[j];
            j--;
        }
        if (this->data[j + 1] != temp) {
            this->data[j + 1] = temp;
        }
    }
}
void Sort::SortPartition(int st, int dr, bool ascendent) {
    int x = this->data[st];
    int i = st + 1;
    int j = dr;
    while (i <= j) {
        if ((this->data[i] <= x && ascendent) ||
            (this->data[i] >= x && !ascendent)) {
            i++;
        }
        if ((this->data[j] >= x && ascendent) ||
            (this->data[j] <= x && !ascendent)) {
            j--;
        }
        if ((i<j && this->data[i]>x && this->data[j] < x && ascendent) ||
            (i<j && this->data[i]<x && this->data[j] > x && !ascendent)) {
            std::swap(this->data[i], this->data[j]);
            i++;
            j--;
        }
    }
    int k = i - 1;
    this->data[st] = this->data[k];
    this->data[k] = x;
    if (st < dr) {
        SortPartition(st, k - 1, ascendent);
        SortPartition(k + 1, dr, ascendent);
    }
}
void Sort::QuickSort(bool ascendent) {
    SortPartition(0, this->size - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent) {
    int i, n1, last = this->size - 1;
    
    while (last > 0) {
        n1 = last - 1;
        last = 0;
        for (i = 0; i <= n1; i++) {
            if (this->data[i] > this->data[i + 1] && ascendent) {
                std::swap(this->data[i], this->data[i + 1]);
                last = i;
            }
            else if (this->data[i] < this->data[i+1] && !ascendent) {
                std::swap(this->data[i], this->data[i + 1]);
                last = i;
            }
        }
    }
}
void Sort::Print() {
    std::cout << this->size << " - ";
    for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i] << " ";
    }
    std::cout << "\n";
}
int  Sort::GetElementsCount() {
    return this->size;
}
int  Sort::GetElementFromIndex(int index) {
    if (index < 0 || index >= this->size) {
        return ~0 >> 1;
    }

    return this->data[index];
}
