#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* constructors */
Fixed::Fixed() : fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) 
	: fixed_point_num( num << Fixed::fractional_bits ) {
	std::cout << "Int constructor called" << std::endl; 
}

Fixed::Fixed(const float num) 
	: fixed_point_num( (int)(roundf(num * (1 << Fixed::fractional_bits))) ) {
	std::cout << "Float constructor called" << std::endl;
}

/* copy constructor */
Fixed::Fixed(const Fixed& x) {
	std::cout << "Copy constructor called" << std::endl;
	*this = x;
}

/* destructor */
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/* operator overloadings */
Fixed& Fixed::operator=(const Fixed& x) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &x)
		this->fixed_point_num = x.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& x) {
    os << x.toFloat();
    return os; 
}

/* member functions */
int Fixed::getRawBits(void) const {
    return (this->fixed_point_num);
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point_num = raw;
}

float Fixed::toFloat(void) const {
    return ((float)(this->fixed_point_num) / (1 << Fixed::fractional_bits));
}

int Fixed::toInt(void) const {
    return (this->fixed_point_num >> Fixed::fractional_bits);
}