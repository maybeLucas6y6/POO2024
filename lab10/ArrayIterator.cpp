#include "Array.hpp"

template<typename T>
ArrayIterator<T>::ArrayIterator(int index, Array<T>& array)
    : Current(index)
    , Arr(array)
{
}

template<typename T>
ArrayIterator<T>& ArrayIterator<T>::operator++() {
    Current++;
    return *this;
}

template<typename T>
ArrayIterator<T>& ArrayIterator<T>::operator--() {
    Current--;
    return *this;
}

template<typename T>
bool ArrayIterator<T>::operator==(const ArrayIterator<T>& other) {
    return Current == other.Current;
}

template<typename T>
bool ArrayIterator<T>::operator!=(const ArrayIterator<T>& other) {
    return Current != other.Current;
}

template<typename T>
T* ArrayIterator<T>::GetElement() {
    return &Arr[Current];
}
