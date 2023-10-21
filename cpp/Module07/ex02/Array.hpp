#ifndef ARRAY_HPP 
# define ARRAY_HPP

template<typename T>
class Array {
    T *arr;

public:
    Array();
    Array(unsigned int n);
    Array(const Array & obj);
    Array& operator=(const Array & obj);
    ~Array();

    T& operator[](int idx);
    unsigned int size() const ;
};

#endif