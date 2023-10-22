#include <iostream>

template <typename T>
Array<T>::Array() : _size(0) {
    this->_arr = new T[this->_size];
    std::cout << "\033[0;32m" << "An empty array has been created." << "\033[0m" << std::endl;
    std::cout << "{ }" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    this->_arr = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
        this->_arr[i] = T();

    std::cout << "\033[0;32m" <<  "An array of size " << this->_size << " has been created." << "\033[0m" << std::endl; 
    std::cout << "{ ";
    if (this->_size > 0)
        std::cout << this->_arr[0];
    for (unsigned int i = 1; i < this->_size; i++)
        std::cout << ", " << this->_arr[i];
    std::cout << " }" << std::endl;
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
        for (unsigned int i = 0; i < this->_size; i++)
            this->_arr[i] = obj._arr[i];

        std::cout << "\033[0;32m" << "An array of size " << this->_size << " has been copied." << "\033[0m" << std::endl; 
        std::cout << "{ ";
        if (this->_size > 0)
            std::cout << this->_arr[0];
        for (unsigned int i = 1; i < this->_size; i++)
            std::cout << ", " << this->_arr[i];
        std::cout << " }" << std::endl;
        }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    if (this->_arr)
        delete[] this->_arr;

    std::cout << "\033[0;32m" << "An array of size " << this->_size << " has been deleted." << "\033[0m" << std::endl; 
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