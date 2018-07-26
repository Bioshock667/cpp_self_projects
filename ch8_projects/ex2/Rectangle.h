#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "ccc_win.h"

class Rectangle:public Shape {
	public:
		Rectangle(Point p1 = Point(0,0), Point p2=Point(1,1));
		virtual double get_area() const;
		virtual void plot();
		virtual Shape* make_shape(Point p = Point(0,0));
	protected:
		Point point2;
};
#endif
