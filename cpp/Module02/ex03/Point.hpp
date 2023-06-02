#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const float _x, const float _y);
	Point(const Point &x);
	Point& operator=(const Point &x);
	~Point();


};

#endif