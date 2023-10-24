#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class NotFoundException: public std::exception {
public:
    const char* what() const throw() {
        return "not found";
    }
};

template <typename T>
void easyfind(const T& container, int target) {
    typename T::const_iterator it;
    
    it = std::find(container.begin(), container.end(), target);
    std::cout << target << " is ";
    if (it == container.end())
        throw NotFoundException();
    std::cout << "found" << std::endl;
}

#endif