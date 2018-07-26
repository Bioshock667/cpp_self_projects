#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square:public Rectangle {
	public:
		Square(Point p = Point(0,0),double n = 1);
		virtual double get_area() const;
		virtual void plot();
		virtual Shape* make_shape(Point p = Point(0,0));
	private:
		double n;
};
	
#endif
