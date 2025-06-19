#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        T *data;
        unsigned int len;
    public:
        Array(void) : data(NULL), len(0) {std::cout <<"Default constructor called\n";}
        Array(unsigned int n) : data(NULL), len(n) 
        {
            if (n > 0) 
            {
                data = new T[n];
                for (unsigned int i = 0; i < n; ++i)
                    data[i] = T();
            }

            std::cout <<"arr_len constructor called\n";

        }
        
        Array(const Array &cpy)
        {
            if (cpy.len > 0)
            {
                this->data = new T[cpy.len];
                this->len = cpy.len;
                for (unsigned int i = 0; i < cpy.len; i++)
                    this->data[i] = cpy.data[i];
            }
            std::cout <<"copy constructor called\n";
        }
        
        ~Array(void) 
        {
            delete [] this->data; 
            std::cout << "Destructor called\n";
        }

        Array& operator=(const Array &cpy) 
        {
            if (this != &cpy)
            {
                delete [] this->data;
                this->data = new T[cpy.len];
                this->len = cpy.len;
                for (unsigned int i = 0; i < cpy.len; i++)
                    this->data[i] = cpy.data[i];
            }
            std::cout << "Assignment operator used\n";
            return *this;
        }

        //suscript operator
        T& operator[](unsigned int index) 
        {
            if (index >= len)
                throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        //getter
        unsigned int size() const 
        {
            return len;
        }

};

#endif