#pragma once

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstring>
#include <cassert>

template<typename T>
class Tree;

template<typename T>
class Node {
    T data;
    size_t size, capacity;
    Node<T>** children;
    friend Tree<T>;
public:
    Node() = delete;
    Node(T data)
    : data(data)
    , size(0)
    , capacity(1)
    , children(new Node<T>*[1])
    {
        printf("ctor normal %p\n", this);
    }
    Node(const Node& other)
    : data(other.data)
    , size(other.size)
    , capacity(other.capacity)
    {
        printf("ctor copy %p", this);
        if (this->children != nullptr) {
            delete[] this->children;
        }

        this->children = new Node<T>*[this->size];
        for (size_t i = 0; i < this->size; i++) {
            *this->children[i] = *other.children[i];
        }
    }
    Node(Node&& other)
    : data(std::move(other.data))
    , size(other.size)
    , capacity(other.capacity)
    {
        printf("ctor move %p\n", this);
        if (this->children != nullptr) {
            delete[] this->children;
        }

        this->children = new Node<T>*[this->size];
        for (size_t i = 0; i < this->size; i++) {
            this->children[i] = other.children[i];
            other.children[i] = nullptr;
        }
    }
    Node& operator=(const Node& other) {
        printf("operator= copy %p\n", this);
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;

        if (this->children != nullptr) {
            delete[] this->children;
        }

        this->children = new Node<T>*[this->size];
        for (size_t i = 0; i < this->size; i++) {
            *this->children[i] = *other.children[i];
        }

        return *this;
    }
    Node& operator=(Node&& other) {
        printf("operator= move %p\n", this);
        this->data = std::move(other.data);
        this->size = other.size;
        this->capacity = other.capacity;

        if (this->children != nullptr) {
            delete[] this->children;
        }

        this->children = new Node<T>*[this->size];
        for (size_t i = 0; i < this->size; i++) {
            this->children[i] = other.children[i];
            other.children[i] = nullptr;
        }
        
        return *this;
    }
    void add_child(Node* child) {
        if (this->size == this->capacity) {
            this->capacity *= 2;
            Node<T>** buf = new Node<T>*[this->capacity];

            memcpy(buf, this->children, this->size * sizeof(Node<T>*));
            delete[] this->children;
            this->children = buf;
        }

        this->children[this->size] = child;
        this->size++;
    }
    void add_child_at(Node* child, size_t index) {
        assert(index >= 0 && index < this->size);

        if (this->size == this->capacity) {
            this->capacity *= 2;
            Node<T>** buf = new Node<T>*[this->capacity];

            memcpy(buf, this->children, this->size * sizeof(Node<T>*));
            delete[] this->children;
            this->children = buf;
        }

        for (size_t i = this->size; i > index; i--) {
            this->children[i] = std::move(this->children[i - 1]);
        }

        this->children[index] = child;
        this->size++;
    }
    ~Node() {
        printf("dtor %p\n", this);
        for (size_t i = 0; i < this->size; i++) {
            if (this->children[i] != nullptr) {
                delete this->children[i];
            }
        }
        if (this->children != nullptr) {
            delete[] this->children;
        }
    }
    friend std::ostream& operator<<(std::ostream& stream, const Node<T>* node) {
        stream << node->data;
        return stream;
    }
};

template<typename T>
class Tree {
    Node<T>* root;
    void iterate(Node<T>* node, void (*f)(Node<T>*&)) {
        if (node == nullptr) {
            return;
        }
        f(node);

        for (size_t i = 0; i < node->size; i++) {
            iterate(node->children[i], f);
        }
    }
    bool find_node_and_delete_it(Node<T>*& node, const Node<T>* target) {
        if (node == nullptr) {
            return false;
        }

        if (node == target) {
            delete node;
            node = nullptr;

            return true;
        }

        if (node->size == 0) {
            return false;
        }
        for (size_t i = 0; i < node->size; i++) {
            if (find_node_and_delete_it(node->children[i], target)) {
                for (size_t j = i; j < node->size - 1; i++) {
                    node->children[i] = std::move(node->children[i + 1]);
                    node->size--;
                }
                return false;
            }
        }
        return false;
    }
    Node<T>* iterate_and_find(Node<T>* node, const T& target, bool (*f)(const T&, const T&)) {
        if (node == nullptr) {
            return nullptr;
        }

        if (f(node->data, target)) {
            return node;
        }

        for (size_t i = 0; i < node->size; i++) {
            auto res = iterate_and_find(node->children[i], target, f);
            if (res != nullptr) {
                return res;
            }
        }
        return nullptr;
    }
public:
    Tree()
    : root(nullptr)
    {

    }
    Tree(const Tree& other);
    Tree(const Tree&& other);
    Tree operator=(const Tree& other);
    Tree operator=(const Tree&& other);
    Node<T>* add_node(Node<T>* parent, const T& child_data) {
        auto child = new Node<T>(child_data);
        if (parent == nullptr) {
            if (this->root == nullptr) {
                this->root = child;
            }
            else {
                child->add_child(this->root);
                this->root = child;
            }
        }
        else {
            parent->add_child(child);
        }
        return child;
    }
    Node<T>* get_node(const Node<T>* parent, size_t index) {
        if (parent == nullptr) {
            return this->root;
        }

        assert(index >= 0 && index < parent->size);

        return parent->children[index];
    }
    void delete_node(const Node<T>* node) {
        if (node == nullptr) {
            return;
        }

        if (node == this->root) {
            delete this->root;
            this->root = nullptr;
            return;
        }

        for (size_t i = 0; i < this->root->size; i++) {
            if (find_node_and_delete_it(this->root->children[i], node)) {
                for (size_t j = i; j < this->root->size - 1; i++) {
                    this->root->children[i] = std::move(this->root->children[i + 1]);
                    this->root->size--;
                }
                return;
            }
        }
    }
    Node<T>* find_node(const T& value, bool (*f)(const T& a, const T& b)) {
        for (size_t i = 0; i < this->root->size; i++) {
            auto res = iterate_and_find(this->root->children[i], value, f);
            if (res != nullptr) {
                return res;
            }
        }
        return nullptr;
    }
    Node<T>* insert_node(Node<T>* parent, size_t index, const T& data) {
        auto child = new Node<T>(data);
        if (parent == nullptr) {
            child->add_child(this->root);
            this->root = child;
        }
        else {
            parent->add_child_at(child, index);
        }
        return child;
    }
    void sort(Node<T>* node, bool (*f)(const T& a, const T& b)) {
        if (node == nullptr) {
            return;
        }

        assert(node->size > 0);
        for (size_t i = 0; i < node->size - 1; i++) {
            for (size_t j = i + 1; j < node->size; j++) {
                if (f != nullptr && !f(node->children[i]->data, node->children[j]->data)) {
                    std::swap(node->children[i], node->children[j]);
                }
                else if (node->children[i]->data > node->children[j]->data) {
                    std::swap(node->children[i], node->children[j]);
                }
            }
        }
    }
    size_t count(Node<T>* node) {
        if (node == nullptr) {
            return 0;
        }

        size_t cnt = node->size;
        for (size_t i = 0; i < node->size; i++) {
            cnt += count(node->children[i]);
        }
        return cnt;
    }
    void print() {
        if (this->root == nullptr) {
            return;
        }

        std::cout << this->root->data << " ";

        for (size_t i = 0; i < this->root->size; i++) {
            iterate(this->root->children[i], [](Node<T>*& node){
                std::cout << node->data << " ";
            });
        }
        std::cout << "\n";
    }
    ~Tree() {
        if (this->root != nullptr) {
            delete this->root;
        }
    }
};
