#ifndef FIXED_H
# define FIXED_H

class Fixed {
private:
	int fixed_point_num;
	static const int fractional_bits = 8;

public:
	Fixed();							
	Fixed(const Fixed& x);				
	Fixed& operator=(const Fixed& x);	
	~Fixed();							

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif