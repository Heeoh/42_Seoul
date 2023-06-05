#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* constructors */
Fixed::Fixed() : fixed_point_num(0) {}

Fixed::Fixed(const int num) 
	: fixed_point_num(num << Fixed::fractional_bits) {}

Fixed::Fixed(const float num) 
	: fixed_point_num( (int)(roundf(num * (1 << Fixed::fractional_bits))) ) {}

/* copy constructor */
Fixed::Fixed(const Fixed& x) {
	*this = x;
}

/* destructor */
Fixed::~Fixed() {}

/* operator overloadings */
Fixed& Fixed::operator=(const Fixed& x) {
	if (this != &x)
		this->fixed_point_num = x.getRawBits();
	return (*this);
}

/* comparison operators overloading */
bool Fixed::operator>(const Fixed& x) const {
	return (this->fixed_point_num > x.fixed_point_num);
}

bool Fixed::operator<(const Fixed& x) const {
	return (this->fixed_point_num < x.fixed_point_num);
}

bool Fixed::operator>=(const Fixed& x) const {
	return (this->fixed_point_num >= x.fixed_point_num);
}

bool Fixed::operator<=(const Fixed& x) const {
	return (this->fixed_point_num <= x.fixed_point_num);
}

bool Fixed::operator==(const Fixed& x) const {
	return (this->fixed_point_num == x.fixed_point_num);
}

bool Fixed::operator!=(const Fixed& x) const {
	return (this->fixed_point_num != x.fixed_point_num);
}
	
/* arithmetic operators overloading */
Fixed Fixed::operator+(const Fixed& x) const {
	return ( Fixed(this->toFloat() + x.toFloat()) );
}

Fixed Fixed::operator-(const Fixed& x) const {
	return ( Fixed(this->toFloat() - x.toFloat()) );
}

Fixed Fixed::operator*(const Fixed& x) const {
	return ( Fixed(this->toFloat() * x.toFloat()) );
}

Fixed Fixed::operator/(const Fixed& x) const {
	return ( Fixed(this->toFloat() / x.toFloat()) );
}

/* increment/decrement operators overloading */
Fixed& Fixed::operator++(void) {
	this->fixed_point_num++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	const Fixed temp(*this);
	this->fixed_point_num++;
	return (temp);
}

Fixed& Fixed::operator--(void) {
	this->fixed_point_num--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	const Fixed temp(*this);
	this->fixed_point_num--;
	return (temp);
}

/* min & max overloaded member functions */
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return ( (a.getRawBits() <= b.getRawBits()) ? a : b );
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return ( (a.getRawBits() >= b.getRawBits()) ? a : b );
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ( (a.getRawBits() <= b.getRawBits()) ? a : b );
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ( (a.getRawBits() >= b.getRawBits()) ? a : b );
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

std::ostream&	operator<<(std::ostream& os, const Fixed& x) {
    os << x.toFloat();
    return os; 
}