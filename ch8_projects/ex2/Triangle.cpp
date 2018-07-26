#include "Triangle.h"
#include <cmath>

Triangle::Triangle(Point p1, Point p2, Point p3):Shape(p1) {
	this->point2 = p2;
	this->point3 = p3;
}

double Triangle::get_area() const {
	double x1 = point1.get_x();
	double x2 = point2.get_x();
	double y1 = point1.get_y();
	double y2 = point2.get_y();
	double base = std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)); //get the length of the base

	double xm = (x2 - x1) / 2.0 + x1;
	double ym = (y2 - y1) / 2.0 + y1;
	double x3 = point3.get_x();
	double y3 = point3.get_y();
	double height = std::sqrt((x3-xm)*(x3-xm) + (y3-ym)*(y3-ym)); //get the length from middle of base to 3rd vertex

	return 0.5 * base * height;
}

void Triangle::plot() {
	cwin << Line(point1, point2) << Line(point2, point3) << Line(point3, point1);
}

Shape* Triangle::make_shape(Point p) {
	Point p1 = p,
	      p2 = p,
	      p3 = p;
	p1.move(0,8);
	//make 3 points and move them by one unit
	const double x = 0.866 * 8; //cos(30deg)
	const double y = 0.5 * 8; //sin(30deg)
	p2.move(-x,-y);
	p3.move(x,-y);

	return new Triangle(p1,p2,p3);
}
