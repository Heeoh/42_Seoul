#include <iostream>

template <typename T>
Array<T>::Array() : _arr(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {
    for (unsigned int i=0; i<n; i++)
        this->_arr[i] = T();
}

template <typename T>
Array<T>::Array(const Array & obj) {
	this->_arr = NULL;
    *this = obj;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array & obj) {
    if (this != &obj) {
        if (this->_arr != NULL)
			delete [] this->_arr;

		this->_size = obj.size();
		this->_arr = new T[this->_size];
        for (unsigned int i=0; i<this->_size; i++)
            this->_arr[i] = obj._arr[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    if (this->_arr)
        delete[] this->_arr;
}

template <typename T>
T& Array<T>::operator[](int idx) const {
	unsigned int uidx = static_cast<unsigned int>(idx);
    if (uidx < 0 || uidx >= this->_size)
        throw std::out_of_range("Index out of range");
    return this->_arr[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}