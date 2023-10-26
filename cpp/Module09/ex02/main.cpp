#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac <= 1) {
        std::cout << "Error: Invalid argument count" << std::endl;
        return 1;
    }

    try {
        PmergeMe a(ac, av);
        
        std::cout << "Before:\t";
        a.printNums();

        a.sortVec();
        a.sortList();
        a.sortDeq();

        std::cout << "After:\t";
        a.printNums();
        a.printExecutionTimes();
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

}