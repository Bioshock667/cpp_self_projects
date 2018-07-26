/* Self Assignment Project
   Programmer: Seth Lemanek
   Number in text: P8.11
   Description in text
	Implement a base class Shape and derived classes Rectangle, Triangle, and Square.  Derive Square from Rectangle.
	Supply virtual functions double area() and void plot(). Fill a vector of Shape* pointers with a mixture of the shapes,
	plot them all, and compute the total Area.
   Algorithm
	1.Create a Base class, Shape with functions area and plot()
	2.Create a Rectangle and Triangle class, derived from Shape
	3.Create a Square class derived from Rectangle class
	4.Instantiate a vector of Shape* pointing to different derived objects and test them
*/
#include "ccc_win.h"
#include <iostream>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"


int ccc_win_main()
{  
	std::vector<Shape*> shapes;
	shapes.push_back(new Rectangle()); 
	shapes.push_back(new Rectangle(Point(1,2),Point(-1,0)));

	shapes.push_back(new Square());
	shapes.push_back(new Square(Point(3,2),5));

	shapes.push_back(new Triangle(Point(0, 1),Point(2,0), Point(-2,0)));
	shapes.push_back(new Triangle(Point(1,0), Point(0,2),Point(0,0)));
	
	for(int i = 0; i < 6 ; i++){
		std::cout << "Shape " << i << " area: " << shapes[i]->get_area() << std::endl;
		shapes[i]->plot();
		cwin.get_mouse("Click to continue");
	}
	return 0; // terminate program with zero errors.

}
