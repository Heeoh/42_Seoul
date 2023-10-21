#ifndef ARRAY_HPP 
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
private:
    T * _arr;
	unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array & obj);
    Array& operator=(const Array & obj);
    ~Array();

    T& operator[](int idx) const ;
    unsigned int size() const ;
};

# include "Array.tpp"

#endif