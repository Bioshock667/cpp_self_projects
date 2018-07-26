/* C++ Self Assignment
   Programmer: Seth Lemanek
   Number in text: P8.1
   Description in text
	Derive a class Programmer from Employee.  Supply a constructor Programmer(string name, double salary)
	that calls the base-class constructor.  Supply a function get_name that returns in the format "Hacker, Harry
	(Programmer)".
   Algorithm
	1.Write a derived class from Employee
	2.create a statically-bound member function "get_name" for derived class Programmer that returns a string of the name + "(Programmer)"
	3.Test it with an instance and output the "get_name" result.
*/
#include "programmer.h"
#include <iostream>
#include <string>
int main() {
    std::string name = "Hacker, Harry";
    double salary = 100000;
    Programmer p(name, salary);
    std::cout << p.get_name() << std::endl;
}
