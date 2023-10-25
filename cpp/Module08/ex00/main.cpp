#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "easyfind.hpp"

#include <cstdlib>
#include <ctime>

#define MAX_VAL 100000

int main() {
    std::srand(time(NULL));

    std::vector<int> vec;
    std::list<int> myList;
    std::set<int> mySet;

    for (int i = 0; i < MAX_VAL; i++) {
        vec.push_back(i);
        myList.push_back(i);
        mySet.insert(i);
    }

    std::cout << "\033[0;35m" << "[ vector ]" << "\033[0m" << std::endl;
    try {
        std::cout << *(::easyfind(vec, 0)) << std::endl; 
        std::cout << *(::easyfind(vec, MAX_VAL - 1)) << std::endl; 
        std::cout << *(::easyfind(vec, rand() % (MAX_VAL * 3))) << std::endl; 
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[0;35m" << "[ list ]" << "\033[0m" << std::endl;
    try {
        std::cout << *(::easyfind(myList, 0)) << std::endl; 
        std::cout << *(::easyfind(myList, MAX_VAL - 1)) << std::endl; 
        std::cout << *(::easyfind(myList, rand() % (MAX_VAL * 3))) << std::endl; 
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[0;35m" << "[ set ]" << "\033[0m" << std::endl;
    try {
        std::cout << *(::easyfind(mySet, 0)) << std::endl; 
        std::cout << *(::easyfind(mySet, MAX_VAL - 1)) << std::endl; 
        std::cout << *(::easyfind(mySet, rand() % (MAX_VAL * 3))) << std::endl; 
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
}
