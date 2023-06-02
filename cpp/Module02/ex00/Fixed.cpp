#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    
    fixed_point_num = 0;
}

Fixed::Fixed(const Fixed& x)
{
    std::cout << "Copy constructor called" << std::endl;
    
    fixed_point_num = x.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& x)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    fixed_point_num = x.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    
    return fixed_point_num;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_num = raw;
}