
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int num;
        static const int fract_bits_num; //static because shared by all instances of Fixed

    public:
        Fixed( void ); //default constructor
        Fixed( Fixed const &cpy ); //cpy constructor
        ~Fixed( void ); //destructor
        Fixed & operator=(Fixed const &val);
        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

#endif