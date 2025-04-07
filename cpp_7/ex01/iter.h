
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void iter(T* arr, int arr_len, void (*fnc_ptr)(T&))
{
	for (int i = 0; i < arr_len; i++)
	{
		fnc_ptr(arr[i]);
	}

}

template <typename T>

void printElement(T& value) 
{
    std::cout << value << std::endl;
}

#endif
