#ifndef ICON_H
#define ICON_H

#include "ccc_win.h"
#include "Shape.h"
#include "Rectangle.h"

class Icon {
	public:
		Icon(Point p1, Point p2, Shape* shape);
		void draw_self(); //draws the icon itself
		Shape* is_selected(Point p); //returns a Shape if selected
						//return null if not
	private:
		Shape* shape;
		Rectangle border;
		Point point1, point2;
		bool quit = false;
};

#endif
