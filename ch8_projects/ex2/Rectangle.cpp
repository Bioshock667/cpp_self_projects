#include "Rectangle.h"
#include <cmath> //std::abs

Rectangle::Rectangle(Point p1, Point p2):Shape(p1) {this->point2 = p2;}

double Rectangle::get_area() const {
	double x1 = point1.get_x();
	double x2 = point2.get_x();
	double y1 = point1.get_y();
	double y2 = point2.get_y();
	
	double height = std::abs(x2 - x1);
	double width = std::abs(y2 - y1);
	
	return height * width;
}

void Rectangle::plot() {
	Point point3(this->point1.get_x(), this->point2.get_y());
	Point point4(this->point2.get_x(), this->point1.get_y());
	cwin 	<< Line(this->point1,point3)
		<< Line(point3, this->point2)
		<< Line(this->point2, point4)
		<< Line(point4, this->point1);
}

Shape* Rectangle::make_shape(Point p) { 
	Point p1 = p;
	Point p2 = p;

	p1.move(-8, -5);
	p2.move(8, 5);

	return new Rectangle(p1, p2);
}
