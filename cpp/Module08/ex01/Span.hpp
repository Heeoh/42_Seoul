#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
    unsigned int size;
    unsigned int count;
    std::vector<int> nums;

    Span();

public:
    Span(unsigned int n);
    Span(const Span & obj);
    Span& operator=(const Span & obj);
    ~Span();

    void addNumber(int num);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif