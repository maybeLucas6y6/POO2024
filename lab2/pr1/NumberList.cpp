#include "NumberList.h"

#include <cstring>
#include <iostream>

void NumberList::Init(int capacity) {
    this->count = 0;
    this->capacity = capacity;
    this->numbers = new int[capacity];
    memset(this->numbers, 0, capacity * sizeof(int));
}

void NumberList::Add(int x) {
    if (this->count == this->capacity) {
        int* old_data = this->numbers;
        this->capacity *= 2;
        this->numbers = new int[this->capacity];
        memcpy(this->numbers, old_data, this->count);
        delete[] old_data;
    }

    this->numbers[count] = x;
    this->count++;
}

void NumberList::Sort() {
    for(int i = 0; i < this->count - 1; i++) {
        for(int j = i + 1; j < this->count; j++) {
            if (this->numbers[i] > this->numbers[j]) {
                int aux = this->numbers[i];
                this->numbers[i] = this->numbers[j];
                this->numbers[j] = aux;
            }
        }
    }
}

void NumberList::Print() {
    for(int i = 0; i < this->count; i++) {
        std::cout << this->numbers[i] << " ";
    }
    std::cout << "\n";
}

void NumberList::Uninit() {
    delete[] this->numbers;
}
