#include "Circle.h"

CircleShape::CircleShape(Point p, double r):Shape(p) {this->radius = r;}

double CircleShape::get_area() const {
	const double PI = 3.14159;
	return 2.0 * radius * PI;
}

void CircleShape::plot() {
	Circle c(point1, radius);
	cwin << c;
}

Shape* CircleShape::make_shape(Point p) { return new CircleShape(p,8);}
