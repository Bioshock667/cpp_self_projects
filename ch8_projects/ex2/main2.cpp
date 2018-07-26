/* Self Assignment Project
   Programmer: Seth Lemanek
   Number in text: P8.12
   Description in text
   	Use Exercise P8.11 as the basis for a drawing program. Users can
	place various shapes onto the screen by clicking on a shape icon and
	then clicking on the desired screen location.
   Algorithm
	1.Create an Icon class to represent icons on screen used to check input
	2.Icon points to a new Shape based on its shape's type
	3.Once selected, program asks for location to plot the new Shape
	4.Continue prompting for icon selection and location until user clicks quit
*/
#include "ccc_win.h"
#include <iostream>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Icon.h"

int ccc_win_main()
{
	cwin.coord(-100, 100, 100, -100);
	Icon rec_icon(Point(-100, 70), Point(-80,90), new Rectangle());
	Icon sqr_icon(Point(-100, 50), Point(-80,69), new Square());
	Icon tri_icon(Point(-100, 30), Point(-80,49), new Triangle());
	Icon quit(Point(-100, 10),Point(-80, 29), NULL);
	rec_icon.draw_self();
	sqr_icon.draw_self();
	tri_icon.draw_self();
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
			if(selection != NULL){
				Point loc = cwin.get_mouse("Select a location");
				selection = selection->make_shape(loc);
				selection->plot();
			}
		}
	}
	return 0; // terminate program with zero errors.

}
