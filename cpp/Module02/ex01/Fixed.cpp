#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* constructor */
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    
    this->fixed_point_num = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Default constructor called" << std::endl;
    
    this->fixed_point_num = num << this->fractional_bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Default constructor called" << std::endl;
    
    this->fixed_point_num = (int)(roundf(num * (1 << this->fractional_bits)));
}

/* copy constructor */
Fixed::Fixed(const Fixed& x)
{
    std::cout << "Copy constructor called" << std::endl;
    
    this->fixed_point_num = x.getRawBits();
}

/* operator overloadings */
Fixed& Fixed::operator=(const Fixed& x)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    this->fixed_point_num = x.getRawBits();
    return *this;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& x)
{
    os << x.toFloat();
    return os; 
}

/* destructor */
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/* member functions */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    
    return (this->fixed_point_num);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_num = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)(this->fixed_point_num) / (1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
    return (this->fixed_point_num >> this->fractional_bits);
}