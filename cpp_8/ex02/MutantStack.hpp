#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
    public:
        //creating alias with typedef for cleaner access
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack() {}
        MutantStack(const MutantStack &cpy) : std::stack<T>(cpy) {}
        MutantStack& operator=(const MutantStack &cpy) {
            if (this != &cpy)
                std::stack<T>::operator=(cpy);
            return *this;
        }
        ~MutantStack() {}

        //iterators
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }

        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }

        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }

        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
