#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // STL: std::find
#include <exception>  


template <typename T>
typename T::const_iterator easyfind(const T& container, int value) 
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container.");
    return it;

}
#endif