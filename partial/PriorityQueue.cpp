#include "PriorityQueue.h"

bool my_strcmp(const char* a, const char* b) {
    int i = 0; 
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i]) {
            return false;
        }
        i++;
    }
    if (a[i] != 0 || b[i] != 0) {
        return false;
    }
    return true;
}

PriorityQueue::PriorityQueue(int max_size)
    : capacity(max_size)
    , size(0)
    , data(new int[capacity]{})
{

}

PriorityQueue::~PriorityQueue() {
    delete[] data;
}

PriorityQueue& PriorityQueue::operator+=(int val) {
    if (size == capacity) {
        if (val > data[size - 1]) {
            data[size - 1] = val;
        }
    }
    else {
        data[size] = val;
        size++;
    }
        for (int i = size - 1; i > 0; i--) {
            if (data[i] > data[i - 1]) {
                int aux = data[i];
                data[i] = data[i - 1];
                data[i - 1] = aux;
            }
        }
    return *this;
}

PriorityQueue::operator int() {
    return size;
}

int PriorityQueue::operator--(int val) {
    if (size == 0) {
        return -1; //error
    }

    int x = data[0];
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return x;
}

int PriorityQueue::operator()(const char* key) {
    if (size == 0) {
        return -1; //error
    }

    if (my_strcmp(key, "sum")) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum;
    }
    if (my_strcmp(key, "min")) {
        int m = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < m) {
                m = data[i];
            }
        }
        return m;
    }
    if (my_strcmp(key, "max")) {
        int m = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > m) {
                m = data[i];
            }
        }
        return m;
    }
    return 0;
}
