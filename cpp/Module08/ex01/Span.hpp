#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class CannotFindSpanException: public std::exception {
public:
    const char* what() const throw() {
        return "Insufficient elements in the stroage to find a span.";
    }
};

class Span {
    std::vector<int> nums;

    Span();

public:
    Span(unsigned int n);
    Span(const Span & obj);
    Span& operator=(const Span & obj);
    ~Span();

    void addNumber(int num);
    void addRange(int from, int to);

    template <typename Iter>
    void addRange(Iter begin, Iter end) {
        while (begin != end) {
            this->addNumber(*begin);
            begin++;
        }
    }
    
    unsigned int shortestSpan();
    unsigned int longestSpan();

    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();
    unsigned int getSize();
    unsigned int count();
    
};

#endif