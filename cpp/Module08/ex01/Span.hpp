#ifndef SPAN_HPP
# define SPAN_HPP

class Span {
    unsigned int size;
    unsigned int count;
    int* nums;

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