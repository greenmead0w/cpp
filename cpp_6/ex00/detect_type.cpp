
#include <cctype> //isdigit
#include <cstring> //strlen
#include <cstdlib> //strol
#include <iostream>

//detects the type of the input, retuns ENUM?
//then switch case and create a type depending in case
//then convert
//handle special cases, oveflows, pseudoshits, etc.

std::string detect_type(char *str)
{
    char *endptr;
    std::string res;

    if (std::strlen(str) == 1)
    {
        if (std::isdigit(str[0]))
            res = "int found";
        else
            res = "char found";
        return res;
    }
    long int_value = strtol(str, &endptr, 10);
    if (*endptr == '\0')
       res = "int found";
    else
    {
        float float_value = strtof(str, &endptr);
        if (*endptr == '\0')
            res = "float found";
        else 
        {
            double double_value = strtod(str, &endptr);
            if (*endptr == '\0')
                res = "double found";
            else 
                res = "impossible";
        }
    }
    return res;
}