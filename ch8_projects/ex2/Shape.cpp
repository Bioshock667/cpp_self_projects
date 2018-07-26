#include "Shape.h"

Shape::Shape(Point p) { this->point1 = p;}
double Shape::get_area() const { return 0;}
void Shape::plot() { cwin << Message(this->point1, "I have no Shape! :<");}
Shape* Shape::make_shape(Point p) { return new Shape(p);}
