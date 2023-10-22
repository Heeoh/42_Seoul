#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename F>
void iter(T* array, int length, F func){
    for (int idx = 0; idx < length; idx++)
        func(array[idx]);
}

template<typename T>
void print(T &value) {
    std::cout << value << " ";
}

#endif