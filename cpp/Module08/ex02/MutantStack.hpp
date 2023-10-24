#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
public:
    typedef std::stack<T>   stack;
    typedef typename std::stack<T>::container_type container;
    
    // custom iterator type
    typedef typename container::iterator iterator;
    typedef typename container::reverse_iterator reverse_iterator;

    // iterator functions
    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    reverse_iterator rbegin() {
        return this->c.rbegin();
    }

    reverse_iterator rend() {
        return this->c.rend();
    }

};

#endif