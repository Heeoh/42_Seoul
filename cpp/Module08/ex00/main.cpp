#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "easyfind.hpp"

#define MAX_VAL 100000
int main() {
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
        ::easyfind(vec, 0);
        ::easyfind(vec, MAX_VAL - 1);
        ::easyfind(vec, rand() % (MAX_VAL * 5));
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[0;35m" << "[ list ]" << "\033[0m" << std::endl;
    try {
        ::easyfind(myList, 0);
        ::easyfind(myList, MAX_VAL - 1);
        ::easyfind(myList, rand() % (MAX_VAL * 5));
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[0;35m" << "[ set ]" << "\033[0m" << std::endl;
    try {
        ::easyfind(mySet, 0);
        ::easyfind(mySet, MAX_VAL - 1);
        ::easyfind(mySet, rand() % (MAX_VAL * 5));
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
}
