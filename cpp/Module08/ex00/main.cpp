#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    std::list<int> myList;
    std::set<int> mySet;

    for (int i=0; i<10; i++) {
        vec.push_back(i);
        myList.push_back(i);
        mySet.insert(i);
    }

    try {
        ::easyfind(vec, 3);
        ::easyfind(vec, 20);
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

   try {
        ::easyfind(myList, 3);
        ::easyfind(myList, 20);
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    try {
        ::easyfind(mySet, 3);
        ::easyfind(mySet, 20);
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
}
