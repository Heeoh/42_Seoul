#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {
    std::cout << "Base default destructer called" << std::endl;
}

A::~A() {
    std::cout << "A default destructer called" << std::endl;
}

B::~B() {
    std::cout << "B default destructer called" << std::endl;
}

C::~C() {
    std::cout << "C default destructer called" << std::endl;
}

Base *generate(void) {
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

void identify(Base *p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Invalid Type" << std::endl;
}

void identify(Base &p) {
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
                std::cout << "Invalid Type" << std::endl;
            }
        }
    }
}