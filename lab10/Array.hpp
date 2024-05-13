#pragma once

class Compare {
public:
    virtual int CompareElements(const void* e1, const void* e2) = 0;
};

template<typename T>
class Array;

template<typename T>
class ArrayIterator {
private:
    int Current;
    const Array<T>& Arr;
public:
    ArrayIterator(int index, Array<T>& array);
    ArrayIterator& operator++();
    ArrayIterator& operator--();
    bool operator==(const ArrayIterator<T>& other);
    bool operator!=(const ArrayIterator<T>& other);
    T* GetElement();
};

template<typename T>
class Array {
private:
    int Size;
    int Capacity;
    T** List;
public:
    Array();
    ~Array();
    Array(int capacity);
    Array(const Array<T>& otherArray);

    // DACA NU PUNEAM CONST AICI NU MERGEA
    T& operator[] (int index) const; // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem);
    const Array<T>& Insert(int index, const T& newElem);
    const Array<T>& Insert(int index, const Array<T> otherArray);
    const Array<T>& Delete(int index);

    bool operator=(const Array<T>& otherArray);

    void Sort();
    void Sort(int(*compare)(const T&, const T&));
    void Sort(Compare *comparator);

    // cu presupunerea ca vectorul e deja sortat
    int BinarySearch(const T& elem);
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));
    int BinarySearch(const T& elem, Compare *comparator);

    int Find(const T& elem);
    int Find(const T& elem, int(*compare)(const T&, const T&));
    int Find(const T& elem, Compare *comparator);
    int GetSize(); 
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();

    void Print();
    void Clear();
};
