#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "ccc_win.h"

class Triangle:public Shape {
	public:
		Triangle(Point p1 = Point(0,0), Point p2 = Point(0,1), Point p3 = Point(1,1));
		virtual double get_area() const;
		virtual void plot();
		virtual Shape* make_shape(Point p = Point(0,0));
	protected:
		Point point2;
		Point point3;
};

#endif
