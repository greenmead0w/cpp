
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
        int getRawBits( void ) const;
        void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &num);

#endif