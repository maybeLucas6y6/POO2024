#pragma once

#include <cassert>
#include <cstddef>
#include <iostream>
#include <utility>
#include <cstring>

template<typename T>
class Vector {
    T* data;
    size_t size, capacity;
public:
    Vector()
        : data(new T[1])
        , size(0)
        , capacity(1)
    {

    }
    ~Vector() {
        if (this->data != nullptr) {
            delete[] data;
        }
    }
    void push_back(const T& item) {
        if (this->size == this->capacity) {
            this->capacity *= 2;
            T* buf = new T[this->capacity];
            for (size_t i = 0; i < this->size; i++) {
                buf[i] = std::move(this->data[i]);
            }
            delete[] data;
            data = buf;
        }
        this->data[this->size] = std::move(item);
        this->size++;
    }
    void push_front(const T& item) {
        // std::cout << "push_front start " << this->size
        //     << "/" << this->capacity << "\n";
        if (this->size == this->capacity) {
            this->capacity *= 2;
            T* buf = new T[this->capacity];
            for (size_t i = 0; i < this->size; i++) {
                buf[i] = std::move(this->data[i]);
            }
            delete[] data;
            data = buf;
        }
        for (size_t i = this->size; i > 0; i--) {
            this->data[i] = std::move(this->data[i - 1]);
        }
        this->data[0] = std::move(item);
        this->size++;
    }
    const T& pop_back() {
        return this->data[--this->size];
    }
    T pop_front() {
        assert(this->size > 0);

        this->size--;
        T item = this->data[0];
        for (size_t i = 0; i < this->size; i++) {
            this->data[i] = this->data[i + 1];
        }
        return item;
    }
    void remove(size_t index) {
        assert(index >= 0 && index < this->size);

        this->size--;
        for (size_t i = index; i < this->size; i++) {
            this->data[i] = this->data[i + 1];
        }
    }
    void insert(size_t index, const T& item) {
        assert(index >= 0 && index <= this->size);

        if (this->size == this->capacity) {
            this->capacity *= 2;
            T* buf = new T[this->capacity];
            for (size_t i = 0; i < this->size; i++) {
                buf[i] = std::move(this->data[i]);
            }
            delete[] data;
            data = buf;
        }
        for (size_t i = this->size; i > index; i--) {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = std::move(item);
        this->size++;
    }
    void sort(bool (*f)(const T&, const T&)) {
        for (size_t i = 0; i < this->size - 1; i++) {
            for (size_t j = i + 1; j < this->size; j++) {
                if (f != nullptr && !f(this->data[i], this->data[j])) {
                    std::swap(this->data[i], this->data[j]);
                }
                else if (this->data[i] > this->data[j]) {
                    std::swap(this->data[i], this->data[j]);
                }
            }
        }
    }
    T& get(size_t index) {
        assert(index >= 0 && index < this->size);

        return this->data[index];
    }
    void set(size_t index, const T& item) {
        assert(index >= 0 && index < this->size);

        this->data[index] = std::move(item);
    }
    size_t count() {
        return this->size;
    }
    size_t first_index_of(const T& item, bool (*f)(const T&, const T&)) {
        for (size_t i = 0; i < this->size; i++) {
            if (f != nullptr && f(item, this->data[i])) {
                return i;
            }
            else if (item == this->data[i]) {
                return i;
            }
        }
        return ~0;
    }
    void print() {
        for (size_t i = 0; i < this->size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
    T& operator[](size_t index) {
        assert(index >= 0 && index < this->size);

        return this->data[index];
    }
};
