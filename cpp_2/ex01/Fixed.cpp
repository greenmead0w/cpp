#include "Fixed.hpp"



Fixed::Fixed(int const cpy) {

	std::cout << "Int constructor called\n";
	num = cpy * 256;
}

Fixed::Fixed(float const cpy) {

	std::cout << "Float constructor called\n";
	float temp = 256 * cpy;
	if (cpy >= 0)
		temp += 0.5;
	else 
		temp -= 0.5;
	num = int(temp);

}

float Fixed::toFloat( void ) const {

	return num / 256.0;

}

int Fixed::toInt( void ) const {

	return num / 256;

}

std::ostream &operator<<(std::ostream &output, const Fixed &num) {

	output << num.toFloat(); 
	return output;
}


/*
********
**Ex00**
********
*/

Fixed::Fixed(void) : num(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &cpy) {
    std::cout << "Copy constructor called\n";
    // this->num = cpy.getRawBits();
    *this = cpy; //less efficient because I
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
    // std::cout << "getRawBits member function called\n"; //commented out to match subject message
    return num;
}

void Fixed::setRawBits( int const raw ) {
    num = raw;
    return;
}






