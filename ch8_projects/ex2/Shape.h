#ifndef SHAPE_H
#define SHAPE_H

#include "ccc_win.h"

class Shape {
	public:
		Shape(Point p= Point(0,0));
		virtual double get_area() const;
		virtual void plot();
		virtual Shape* make_shape(Point p = Point(0,0));
	protected:
		Point point1;
};
#endif
