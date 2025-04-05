
#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data {
    public:
        int id;
        std::string name;

        Data(void);
        Data(const Data &cpy);
        Data &operator=(const Data &cpy);
        ~Data(void);

};

#endif