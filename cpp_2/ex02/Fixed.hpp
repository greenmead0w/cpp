
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int num;
        static const int fract_bits_num; //static because shared by all instances of Fixed

    public:
        Fixed( void );
        Fixed( Fixed const &cpy );
		Fixed( int const cpy);
		Fixed( float const cpy);
        ~Fixed( void );
        Fixed & operator=(Fixed const &val);
        //overloading comparison operators
        bool operator>(Fixed const &compare);
        bool operator<(Fixed const &compare);
        bool operator>=(Fixed const &compare);
        bool operator<=(Fixed const &compare);
        bool operator==(Fixed const &compare);
        bool operator!=(Fixed const &compare);
        //overloading arithmetic operators
        Fixed operator+(Fixed const &add);
        Fixed operator-(Fixed const &add);
        Fixed operator*(Fixed const &add);
        Fixed operator/(Fixed const &add);
        //overloading increment operators
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed &operator++(void);
        Fixed &operator--(void);
        //static min/max overloaded functs
        static  Fixed &min(Fixed &num1, Fixed &num2);
        static const Fixed &min(const Fixed &num1, const Fixed &num2);
        static  Fixed &max(Fixed &num1, Fixed &num2);
        static const Fixed &max(const Fixed &num1, const Fixed &num2);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &num);

#endif