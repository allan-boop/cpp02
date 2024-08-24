#pragma once
#include "Fixed.hpp"
#include <iostream>

class Point {
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		~Point();

		Point &operator=(const Point &other);

		const Fixed &getX() const;
		const Fixed &getY() const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};