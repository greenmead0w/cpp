#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed d(2.5f);
    Fixed c(10);
    Fixed b(d);

	a = c;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    //arithmetic operators
    Fixed sum = a + b;
    std::cout << "a + b: " << sum << std::endl;

    Fixed diff = a - b;
    std::cout << "a - b: " << diff << std::endl;

    Fixed prod = a * b;
    std::cout << "a * b: " << prod << std::endl;

	b = 0;
    Fixed div = a / b;
    std::cout << "a / b: " << div << std::endl;

    return 0;
}

// int main() {
//     Fixed a(10);
//     Fixed b(5.5f);

//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;

//     //comparison operators
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;

//     //  min and max
//     std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl;
//     std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;

//     return 0;
// }
