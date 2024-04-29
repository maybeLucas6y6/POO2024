#pragma once

#include <cstdio>
#include <cstring>

template<typename Key, typename Val>
class Map {
    struct Pair {
        Key key;
        Val val;
    };
    struct PairFake {
        Key& key;
        Val& val;
        int& index;
    };
    struct Iterator {
        Pair** data;
        int index;
        Iterator& operator++() {
            this->index++;
            return *this;
        }
        bool operator!=(const Iterator& it) {
            return it.index != this->index;
        }
        PairFake operator*() {
            return { this->data[this->index]->key, this->data[this->index]->val, this->index };
        }
    };
    int size, capacity;
    Pair** data;

    Pair& insert(const Key& key) {
        if (this->size == 0) {
            this->data = new Pair*[1]{};
            this->capacity = 1;
        }
        else if (this->size == this->capacity) {
            Pair** buf = new Pair*[2 * this->capacity]{};
            memcpy(buf, this->data, size * sizeof(Pair*));
            delete[] this->data; // oare cheama dtor cand dealoca vector?
            this->data = buf;
            this->capacity *= 2;
        }

        this->data[this->size] = new Pair{key, {}};
        this->size++;
        return *this->data[this->size - 1];
    }
public:
    Map()
        : size(0)
        , capacity(0)
        , data(nullptr)
    {
    }
    ~Map() {
        if (this->data != nullptr) {
            for (int i = 0; i < this->size; i++) {
                if (this->data[i] != nullptr) {
                    delete this->data[i];
                }
            }
            delete[] this->data;
        }
    }
    Map(const Map<Key, Val>& other) = delete;
    Map(Map<Key, Val>&& other) = delete;
    Map<Key, Val>& operator=(const Map<Key, Val>& other) = delete;
    Map<Key, Val>& operator=(Map<Key, Val>&& other) = delete;
    Val& operator[](const Key& key) {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i]->key == key) {
                return this->data[i]->val;
            }
        }

        return this->insert(key).val;
    }
    void operator=(const Val& val);
    Iterator begin() const {
        return { this->data, 0 };
    }
    Iterator end() const {
        return { this->data, this->size };
    }
    bool Set(const Key& key, const Val& val) {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i]->key == key) {
                this->data[i]->val = val;
                return true;
            }
        }
        return false;
    }
    bool Get(const Key& key, Val& val) {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i]->key == key) {
                val = this->data[i]->val;
                return true;
            }
        }
        return false;
    }
    int Count() {
        return this->size;
    }
    void Clear() {
        for (int i = 0; i < this->size; i++) {
            delete this->data[i];
        }
        this->size = 0;
        this->capacity = 0;
    }
    bool Delete(const Key& key) {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i]->key == key) {
                delete this->data[i];
                for (int j = i; j < this->size - 1; j++) {
                    this->data[j] = this->data[j + 1];
                }
                this->size--;
                return true;
            }
        }
        return false;
    }
    bool Contains(const Key& key) {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i]->key == key) {
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<Key, Val>& map) {
        for (const auto& [key, val, idx] : map) {
            if (!this->Contains(key)) {
                return false;
            }
        }
        return true;
    }
};
