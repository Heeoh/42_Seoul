#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixed_point_num(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& x) {
    std::cout << "Copy constructor called" << std::endl;   
	*this = x; 
}

Fixed& Fixed::operator=(const Fixed& x) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &x)
    	this->fixed_point_num = x.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_num);
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point_num = raw;
}