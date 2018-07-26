#include "Square.h"
#include "ccc_win.h"

Square::Square(Point p,double n) {
	Point p1 = p;
	Point p2 = p;
	p1.move(-(n/2.0),-(n/2.0));
	p2.move(n/2.0,n/2.0);
	
	this->point1 = p1;
	this->point2 = p2;
	this->n = n;
}

double Square::get_area() const {
	return this->n * this->n;
}

void Square::plot() {
	
	Rectangle::plot();
}

Shape* Square::make_shape(Point p) {
	return new Square(p, 8);
}
