#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
private:
	int fixed_point_num;
	static const int fractional_bits = 8;

public:
	// constructors 
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	
	// copy constructor
	Fixed(const Fixed& x);

	// destructor
	~Fixed();
		
	// operator overloadings
	Fixed&					operator=(const Fixed& x);
	friend std::ostream&	operator<<(std::ostream& os, const Fixed& x);

	// comparison operators overloading
	bool	operator>(const Fixed& x) const;
	bool	operator<(const Fixed& x) const;
	bool	operator>=(const Fixed& x) const;
	bool	operator<=(const Fixed& x) const;
	bool	operator==(const Fixed& x) const;
	bool	operator!=(const Fixed& x) const;
	
	// arithmetic operators overloading
	Fixed	operator+(const Fixed& x) const;
	Fixed	operator-(const Fixed& x) const;
	Fixed	operator*(const Fixed& x) const;
	Fixed	operator/(const Fixed& x) const;

	// increment/decrement operators overloading
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	// min & max overloaded member functions
	static Fixed&	min(Fixed& a, Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
	
	// member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

#endif