#include "programmer.h"
//#include <ccc_empl.h>

#include <string>

Programmer::Programmer():Employee(){}

Programmer::Programmer(string name, double salary):Employee(name, salary) {}

std::string Programmer::get_name() const {
    return Employee::get_name() + "(Programmer)";
}
