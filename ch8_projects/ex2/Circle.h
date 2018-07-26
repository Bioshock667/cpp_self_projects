#ifndef CIRCLE_H
#define CIRCLE_h

#include "Shape.h"
#include "ccc_win.h"

class CircleShape:public Shape {
	public:
		CircleShape(Point p = Point(0,0), double r = 1);
		virtual double get_area() const;
		virtual void plot();
		virtual Shape* make_shape(Point p = Point(0,0));
	private:
		double radius;
};
#endif
