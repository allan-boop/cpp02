#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

float area(float x1, float x2, float x3, float y1, float y2, float y3);
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(3, 2);
	Point b(11, 3);
	Point c(7, 12);
	Point p1(7, 5);
	Point p2(11, 8);
	Point p3(4.001, 4.5); // limit
	Point p4(5, 8);
	Point p5(5, 7);

	std::cout << "premier " << bsp(a, b, c, p1) << std::endl;
	std::cout << "deuxieme " << bsp(a, b, c, p2) << std::endl;
	std::cout << "troisieme " << bsp(a, b, c, p3) << std::endl;
	std::cout << "quatrieme " << bsp(a, b, c, p4) << std::endl;
	std::cout << "cinquieme " << bsp(a, b, c, p5) << std::endl;

	return 0;
}