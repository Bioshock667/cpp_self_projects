#include "Icon.h"

Icon::Icon(Point p1, Point p2, Shape* shape):point1(p1),point2(p2),shape(shape), border(Rectangle(p1,p2)) {if(shape == NULL) quit = true;}

void Icon::draw_self() {
	double 	x2 = point2.get_x(),
		x1 = point1.get_x(),
		y2 = point2.get_y(),
		y1 = point1.get_y();

	double mx = (x2 - x1) / 2 + x1;
	double my = (y2 - y1) / 2 + y1;
	Point middle(mx, my);
	border.plot();
	if(quit) {
		middle.move(-5,3);
		cwin << Message(middle, "Quit");
	} else {
	Shape* icon_shape = shape->make_shape(middle);
	icon_shape->plot();
	}
}

Shape* Icon::is_selected(Point p) {
	double sel_x = p.get_x();
	double sel_y = p.get_y();

	double 	x2 = point2.get_x(),
		x1 = point1.get_x(),
		y2 = point2.get_y(),
		y1 = point1.get_y();

	bool in_x_range = (sel_x <= x2) && (sel_x >= x1);
	bool in_y_range = (sel_y <= y2) && (sel_y >= y1);//if point is within the Icon

	if( in_x_range && in_y_range) { //return a copy of the private Shape
		if(quit)
			return new Shape();
		return shape->make_shape();
	}
	return NULL; //return null
}
