#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point(const float _x, const float _y) : x(Fixed(_x)), y(Fixed(_y)) {}

Point::Point(const Point &obj) {
	*this = obj;
}

Point& Point::operator=(const Point &obj) {
	if (this != &obj) {
		this->~Point();
		new (this) Point(obj);
	}

	return (*this);
}

Point::~Point() {}