
#include "Serializer.h"

Serializer::Serializer(void){
    std::cout << "Serializer default constructor\n";
}

Serializer::Serializer(const Serializer &cpy) {
    *this = cpy;
    std::cout << "Serializer copy constructor called\n";
}

Serializer::~Serializer(void) {
    std::cout << "Serializer destructor called\n";
}

Serializer &Serializer::operator=(const Serializer &cpy) {
    if (this != &cpy)
        *this = cpy;

    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
