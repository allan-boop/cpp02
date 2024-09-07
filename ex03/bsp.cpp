#include "Point.hpp"
#include <cstdlib>
#include <cmath>

float area(float x1, float x2, float x3, float y1, float y2, float y3) {
	return std::abs(((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2.0f);
}

bool isOnEdgeOrVertex(float x1, float y1, float x2, float y2, float px, float py) {
    float areaTriangle = area(x1, x2, px, y1, y2, py);
    return areaTriangle == 0.0f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
 	float ax = a.getX().toFloat();
 	float ay = a.getY().toFloat();
 	float bx = b.getX().toFloat();
 	float by = b.getY().toFloat();
 	float cx = c.getX().toFloat();
 	float cy = c.getY().toFloat();
 	float px = point.getX().toFloat();
 	float py = point.getY().toFloat();

    if (isOnEdgeOrVertex(ax, ay, bx, by, px, py) ||
        isOnEdgeOrVertex(bx, by, cx, cy, px, py) ||
        isOnEdgeOrVertex(cx, cy, ax, ay, px, py)) {
        return false;
    }

    if ((px == ax && py == ay) ||
        (px == bx && py == by) ||
        (px == cx && py == cy)) {
        return false;
    }

 	float	areaABC = area(ax, bx, cx, ay, by, cy);
 	float	areaPBC = area(px, bx, cx, py, by, cy);
 	float	areaPCA = area(ax, px, cx, ay, py, cy);
 	float	areaPAB = area(ax, bx, px, ay, by, py);

     const float epsilon = 0.00001f;
     return std::fabs(areaABC - (areaPBC + areaPCA + areaPAB)) < epsilon;
}



