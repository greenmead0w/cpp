#include "Fixed.hpp"


Fixed::Fixed(void) : num(0) {
    std::cout << "Default constructor called\n";
    return;
}

Fixed::Fixed(Fixed const &cpy) {
    std::cout << "Copy constructor called\n";
    this->num = cpy.getRawBits(); //using getRawBits() to access private value
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called\n";
    return;
}

Fixed & Fixed::operator=(Fixed const & val) {
    std::cout << "Copy assignment operator called\n";
    if (this != &val)
        num = val.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
    return num;
}

void Fixed::setRawBits( int const raw ) {
    num = raw;
    return;
}


