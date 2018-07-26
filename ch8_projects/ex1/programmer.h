#ifndef PROGRAMMER_H
#define PROGRAMMER_H 
//#include <ccc_empl.h>
#include "ccc_empl.h"
//#include "cccfiles/ccc_empl.h"
//#include <cccfiles/ccc_empl.h>
//#include "libccc/ccc_empl.h"
//#include "ccc/ccc_empl.h"
//#include <string>

class Programmer: public Employee 
{
    public:
        Programmer();
        Programmer(string name, double salary);
        std::string get_name() const;
};
#endif
