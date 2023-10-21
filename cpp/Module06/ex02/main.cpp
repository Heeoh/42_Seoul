#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static Base *generate(void) {
    int type = std::rand() % 3;

    switch (type) {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    }
    return NULL;
}

static void identify(Base *p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

static void identify(Base &p) {
    try {
        A& refA = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)refA;
    } catch (std::bad_cast & e) {
        try{
            B& refB = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)refB;
        } catch (std::bad_cast & e) {
            try {
                C& refC = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)refC;
            } catch (std::bad_cast & e) {
                std::cout << "Unknown Type" << std::endl;
            }
        }
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Base *random = generate();
    std::cout << "ptr: ";
    identify(random);
    std::cout << "ref: "; 
    identify(*random);
    delete random;

}