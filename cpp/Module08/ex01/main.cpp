#include "Span.hpp"
#include <iostream>

template<typename Iter, typename Func>
void iter(Iter begin, Iter end, Func func) {
    while (begin != end) {
        func(*begin);
        begin++;
    }
}

template<typename T>
void print(T &value) {
    std::cout << value << " ";
}

int main()
{

    std::cout << "\033[0;35m" << "[ default test ]" << "\033[0m" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        ::iter(sp.begin(),sp.end(), print<int>);
        std::cout << std::endl;

        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[0;35m" << "[ addNumber exception test ]" << "\033[0m" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(12);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[0;35m" << "[ span exception test ]" << "\033[0m" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        
        ::iter(sp.begin(),sp.end(), print<int>);
        std::cout << std::endl;

        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[0;35m" << "[ addNumbers ]" << "\033[0m" << std::endl;
    try {
        Span sp = Span(5);
        sp.addRange(1, 5);
        
        ::iter(sp.begin(),sp.end(), print<int>);
        std::cout << std::endl;
        
        Span sp2 = Span(10);
        sp2.addRange(sp.begin(), sp.end() - 2);
        ::iter(sp2.begin(),sp2.end(), print<int>);
        std::cout << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}