#include "Array.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <cstring>

template<typename T>
Array<T>::Array()
    : Size(0)
    , Capacity(0)
    , List(nullptr)
{
}

template<typename T>
Array<T>::Array(int capacity)
    : Size(0)
    , Capacity(capacity)
    , List(new T*[capacity]{})
{
    for (unsigned i = 0; i < Capacity; i++) {
        List[i] = new T();
    }
}

template<typename T>
Array<T>::Array(const Array<T>& otherArray)
    : Size(otherArray.Size)
    , Capacity(otherArray.Capacity)
    , List(new T*[Capacity]{})
{
    for (unsigned i = 0; i < Size; i++) {
        List[i] = new T(*otherArray.List[i]);
    }
}

template<typename T>
Array<T>::~Array() {
    Clear();
}

template<typename T>
T& Array<T>::operator[](int index) const {
    ExceptionInvalidIndex e;
    if (index < 0 || index >= Size) {
        throw e;
    }

    return *List[index];
}

template<typename T>
const Array<T>& Array<T>::operator+=(const T& newElem) {
    Insert(Size, newElem);
    return *this;
}

template<typename T>
const Array<T>& Array<T>::Insert(int index, const T& newElem) {
    ExceptionInvalidIndex e;
    if (index < 0 || index > Size) {
        throw e;
    }

    if (Size == 0) {
        Capacity = 1;
        List = new T*[Capacity]{};
    }
    else if (Size == Capacity) {
        Capacity *= 2;
        T** buf = new T*[Capacity]{};
        memcpy(buf, List, Size * sizeof(T*));
        delete[] List;
        List = buf;
    }

    for (unsigned i = Size; i > index; i--) {
        List[i] = List[i - 1];
    }
    List[index] = new T(newElem);
    Size++;

    return *this;
}

template<typename T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray) {
    ExceptionInvalidIndex e;
    if (index < 0 || index > Size) {
        throw e;
    }

    if (Size + otherArray.Size > Capacity) {
        Capacity = Size + otherArray.Size;        
        T** buf = new T*[Capacity]{};
        memcpy(buf, List, index * sizeof(T*));
        memcpy(reinterpret_cast<char*>(buf) + (index + otherArray.Size) * sizeof(T*), 
                reinterpret_cast<char*>(List) + index * sizeof(T*), (Size - index) * sizeof(T*));
        delete[] List;
        List = buf;
    }

    for (unsigned i = 0; i < otherArray.Size; i++) {
        List[index + i] = new T(*otherArray.List[i]);
    }
    Size += otherArray.Size;

    return *this;
}

template<typename T>
const Array<T>& Array<T>::Delete(int index) {
    ExceptionInvalidIndex e;
    if (index < 0 || index > Size) {
        throw e;
    }

    delete List[index];
    for (unsigned i = index; i < Size - 1; i++) {
        List[i] = List[i + 1];
    }
    Size--;
    List[Size] = nullptr;

    return *this;
}

template<typename T>
bool Array<T>::operator=(const Array<T>& otherArray) {
    Clear();

    if (Size < otherArray.Size) {
        List = new T*[otherArray.Size]{};
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
    }

    for (unsigned i = 0; i < Size; i++) {
        List[i] = new T(*otherArray.List[i]);
    }

    return true;
}

template<typename T>
void Array<T>::Sort() {
    for (unsigned i = 0; i < Size - 1; i++) {
        for (unsigned j = i; j < Size; j++) {
            if (!(*List[i] < *List[j])) {
                std::swap(List[i], List[j]);
            }
        }
    }
}

template<typename T>
void Array<T>::Sort(int(*compare)(const T&, const T&)) {
    for (unsigned i = 0; i < Size - 1; i++) {
        for (unsigned j = i; j < Size; j++) {
            if (compare(*List[i], *List[j]) != -1) {
                std::swap(List[i], List[j]);
            }
        }
    }
}

template<typename T>
void Array<T>::Sort(Compare *comparator) {
    for (unsigned i = 0; i < Size - 1; i++) {
        for (unsigned j = i; j < Size; j++) {
            if (comparator->CompareElements(List[i], List[j]) != -1) {
                std::swap(List[i], List[j]);
            }
        }
    }
}

template<typename T>
int Array<T>::BinarySearch(const T& elem) {
    unsigned st = 0, dr = Size - 1;
    while (st <= dr) {
        unsigned mij = (st + dr) / 2;
        if (*List[mij] == elem) {
            return mij;
        }
        if (*List[mij] > elem) {
            dr = mij - 1;
        }
        else {
            st = mij + 1;
        }
    }
    return -1;
}

template<typename T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
    unsigned st = 0, dr = Size - 1;
    while (st <= dr) {
        unsigned mij = (st + dr) / 2;
        if (compare(*List[mij], elem) == 0) {
            return mij;
        }
        if (compare(*List[mij], elem) == 1) {
            dr = mij - 1;
        }
        else {
            st = mij + 1;
        }
    }
    return -1;
}

template<typename T>
int Array<T>::BinarySearch(const T& elem, Compare *comparator) {
    unsigned st = 0, dr = Size - 1;
    while (st <= dr) {
        unsigned mij = (st + dr) / 2;
        if (comparator->CompareElements(List[mij], &elem) == 0) {
            return mij;
        }
        if (comparator->CompareElements(List[mij], &elem) == 1) {
            dr = mij - 1;
        }
        else {
            st = mij + 1;
        }
    }
    return -1;
}

template<typename T>
int Array<T>::Find(const T& elem) {
    for (unsigned i = 0; i < Size; i++) {
        if (*List[i] == elem) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&)) {
    for (unsigned i = 0; i < Size; i++) {
        if (compare(*List[i], elem) == 0) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int Array<T>::Find(const T& elem, Compare *comparator) {
    for (unsigned i = 0; i < Size; i++) {
        if (comparator->CompareElements(List[i], &elem) == 0) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int Array<T>::GetSize() {
    return Size;
}

template<typename T>
int Array<T>::GetCapacity() {
    return Capacity;
}

template<typename T>
ArrayIterator<T> Array<T>::GetBeginIterator() {
    return { 0, *this };
}

template<typename T>
ArrayIterator<T> Array<T>::GetEndIterator() {
    return { Size, *this };
}

template<typename T>
void Array<T>::Print() {
    /*
    for (unsigned i = 0; i < Size; i++) {
        std::cout << (*this)[i] << ' ';
    }
    */

    for (auto it = GetBeginIterator(); it != GetEndIterator(); ++it) {
        std::cout << *it.GetElement() << ' ';
    }
    std::cout << '\n';
}

template<typename T>
void Array<T>::Clear() {
    if (List != nullptr) {
        for (unsigned i = 0; i < Size; i++) {
            if (List[i] != nullptr) {
                delete List[i];
                List[i] = nullptr;
            }
        }
        delete[] List;
        List = nullptr;
    }
}
