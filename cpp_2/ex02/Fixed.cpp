#include "Fixed.hpp"


bool Fixed::operator>(Fixed const &compare){
    // if (num > compare.getRawBits())
    //     return true;
    // else
    //     return false;
    return num > compare.getRawBits();
}

bool Fixed::operator<(Fixed const &compare) {
    return num < compare.getRawBits();
}

bool Fixed::operator>=(Fixed const &compare) {
    return num >= compare.getRawBits();
}

bool Fixed::operator<=(Fixed const &compare) {
    return num <= compare.getRawBits(); 
}

bool Fixed::operator==(Fixed const &compare) {
    return num == compare.getRawBits();
}

bool Fixed::operator!=(Fixed const &compare) {
    return num != compare.getRawBits();
}

Fixed Fixed::operator+(Fixed const &add) {
    Fixed sum;
    sum.setRawBits(num + add.getRawBits());
    return sum;
}

Fixed Fixed::operator-(Fixed const &add) {
    Fixed sub;
    sub.setRawBits(num - add.getRawBits());
    return sub;
}

Fixed Fixed::operator*(Fixed const &add) {
    Fixed sum;
    sum.setRawBits((num * add.getRawBits()) / 256.0);
    return sum;
}

Fixed Fixed::operator/(Fixed const &add) {
    Fixed sum;
    if (add.getRawBits() == 0)
        std::cout << "you're not crashing me\n";
    else
        sum.setRawBits((num * 256.0) / add.getRawBits()); //multiply to scale up before using toFloat
    return sum;
}

Fixed Fixed::operator++(int) { //post-increment
    Fixed temp(*this);
    num++;
    return temp;
}

Fixed Fixed::operator--(int) { //post-decrement
    Fixed temp(*this);
    num--;
    return temp;
}

Fixed &Fixed::operator++(void) {
    num++;
    return *this;
}

Fixed &Fixed::operator--(void) {
    num--;
    return *this;
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
    if (num1.getRawBits() > num2.getRawBits())
        return num2;
    else
        return num1;
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
    if (num1.getRawBits() > num2.getRawBits())
        return num2;
    else
        return num1;
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
    if (num1.getRawBits() >= num2.getRawBits())
        return num1;
    else
        return num2;
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
    if (num1.getRawBits() >= num2.getRawBits())
        return num1;
    else
        return num2;
}

/*
********
**Ex01**
********
*/

Fixed::Fixed(int const cpy) {

	// std::cout << "Int constructor called\n";
	num = cpy * 256;
}

Fixed::Fixed(float const cpy) {

	// std::cout << "Float constructor called\n";
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
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &cpy) {
    // std::cout << "Copy constructor called\n";
    // this->num = cpy.getRawBits();
    *this = cpy; //less efficient because I
}

Fixed::~Fixed(void) {
    // std::cout << "Destructor called\n";
    return;
}

Fixed & Fixed::operator=(Fixed const & val) {
    // std::cout << "Copy assignment operator called\n";
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