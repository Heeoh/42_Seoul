#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(new T[]) {}

template<typename T>
Array<T>::Array(unsigned int n): arr(new T[n]) {
    for (int i=0; i<n; i++)
        arr[i] = T();
}

template<typename T>
Array<T>::Array(const Array & obj) {
    *this = obj;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array & obj) {
    if (this != &obj) {
        if (this->arr) 
            delete[] this->arr;

        arr = new T[obj.size()];
        for (unsigned int i=0; i<obj.size(); i++)
            this->arr[i] = obj.arr[i];
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    if (this->arr)
        delete[] this->arr;
}

template<typename T>
T& Array<T>::operator[](int idx) {
    if (idx < 0 || idx >= this->size())
        throw std::out_of_range("Index out of range");
    return this->arr[idx];
}

template<typename T>
unsigned int Array<T>::size() const {
    return (this->arr) ? sizeof(this->arr) / sizeof(this->arr[0]) : 0;
}