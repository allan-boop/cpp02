#include "Point.hpp"
#include <iomanip>

Point::Point() : _x(0), _y(0) {
	return;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return;
}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {
	return;
}

Point::~Point() {
	return;
}

Point &Point::operator=(const Point &other) {
    return ((void)other, *this);
}

const Fixed &Point::getX() const {
	return (this->_x);
}

const Fixed &Point::getY() const {
	return (this->_y);
}