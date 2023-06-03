#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
private:
	int 				fixed_point_num;
	static const int	fractional_bits = 8;

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
	
	// member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

#endif