#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class NotFoundException: public std::exception {
public:
    const char* what() const throw() {
        return "Cannot Find";
    }
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int target) {
    typename T::const_iterator it;
    
    it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif