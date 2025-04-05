
#include "Base.h"

Base::~Base(void) {
    std::cout << "Base. Destructor called\n";
}

Base* generate(void) {
    int randValue = std::rand() % 3;
    if (randValue == 0)
    {
        std::cout << "derived class: A generated" << std::endl;
        return new A;
    }
    else if (randValue == 1)
    {
        std::cout << "derived class: B generated" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "derived class: C generated" << std::endl;
        return new C;
    }
}

//if the cast succeeds dynamic_cast returns non-null
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

//references must be bind to valid objects
void identify(Base& p) {
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }
    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }
    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }
    std::cout << "no matching class" << std::endl;
}