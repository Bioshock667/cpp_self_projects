/* Self Assignment Project
   Programmer: Seth Lemanek
   Number in text: P8.13
   Description in text
   	Extend the program of Exercise p8.12 by adding shape type,
	CircleShape. (You cannot call it Circle, becuase they already
	is a Circle class in the graphics library.) Explain what changes
	you needed to make in the program to implement this extension.
	How do virtual functions help in making the program easily extensible.
   Algorithm
   	1.Create a CircleShape class that derives from Shape.
	2.Add a new Icon for the CircleShape
	3.Rerun the drawing program
*/
#include "ccc_win.h"
#include <iostream>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "Icon.h"

int ccc_win_main()
{
	cwin.coord(-100, 100, 100, -100);
	Icon rec_icon(Point(-100, 70), Point(-80,90), new Rectangle());
	Icon sqr_icon(Point(-100, 50), Point(-80,69), new Square());
	Icon tri_icon(Point(-100, 30), Point(-80,49), new Triangle());
	Icon cir_icon(Point(-100, 10), Point(-80, 29), new CircleShape());
	Icon quit(Point(-100, -10),Point(-80, 9), NULL);
	rec_icon.draw_self();
	sqr_icon.draw_self();
	tri_icon.draw_self();
	cir_icon.draw_self();
	quit.draw_self();
	Shape* selection;
	bool loop = true;
	while(loop) {
		Point select = cwin.get_mouse("Click on a shape of your choice");
		if(quit.is_selected(select)) { 
			cout << "Quitting!\n";
			loop = false;
		} else {
			selection = rec_icon.is_selected(select);
			if(selection == NULL)
				selection = sqr_icon.is_selected(select);
			if(selection == NULL)
				selection = tri_icon.is_selected(select);
			if(selection == NULL)
				selection = cir_icon.is_selected(select);
			if(selection != NULL){
				Point loc = cwin.get_mouse("Select a location");
				selection = selection->make_shape(loc);
				selection->plot();
			}
		}
	}
	return 0; // terminate program with zero errors.

}
