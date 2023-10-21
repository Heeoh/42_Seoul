#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Base *random = generate();
    std::cout << "ptr: ";
    identify(random);
    std::cout << "ref: "; 
    identify(*random);
    delete random;

}