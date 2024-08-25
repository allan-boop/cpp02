#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

float area(float x1, float x2, float x3, float y1, float y2, float y3);
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(14, 10);
	Point b(20, 9);
	Point c(2, 2);
	Point p1(1, 1);
	Point p2(3, 3);
	Point p3(14, 10);
	Point p4(16, 8);

	std::cout << "premier " << bsp(a, b, c, p1) << std::endl;
	std::cout << "deuxieme " << bsp(a, b, c, p2) << std::endl;
	std::cout << "troisieme " << bsp(a, b, c, p3) << std::endl;
	std::cout << "quatrieme " << bsp(a, b, c, p4) << std::endl;

	return 0;
}