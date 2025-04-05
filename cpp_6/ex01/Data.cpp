
#include "Data.h"

Data::Data(void) : id(10), name("Mikel"){
    std::cout << "Data default constructor\n";
}

Data::Data(const Data &cpy) {
    *this = cpy;
    std::cout << "Data copy constructor called\n";
}

Data::~Data(void) {
    std::cout << "Data destructor called\n";
}

Data &Data::operator=(const Data &cpy) {
    if (this != &cpy)
    {
        this->id = cpy.id;
        this->name = cpy.name;
    }

    return *this;
}