#ifndef FIXED_H
# define FIXED_H

class Fixed {
private:
	int fixed_point_num;
	static const int fractional_bits = 8;

public:
	Fixed();							// constructors 
	Fixed(const Fixed& x);				// copy constructor
	Fixed& operator=(const Fixed& x);	// copy assignment operator overload
	~Fixed();							// destructor
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif