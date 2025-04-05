
#include "Base.h"

int main() {

    std::srand(static_cast<unsigned int>(std::time(0)));

    Base* ptr = generate();

    std::cout << "Identifying via pointer: ";
    identify(ptr);

    std::cout << "Identifying via reference: ";
    identify(*ptr);

    delete ptr;

    return 0;
}