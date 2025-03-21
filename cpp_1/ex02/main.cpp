#include <string>
#include <iostream>


int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    //print memory addreses
    std::cout << "memory address of the string variable: " << &str << std::endl;
    std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "memory address held by stringREF " << &stringREF << std::endl;

    std::cout << "-------------------------------------------\n";

    //print values
    std::cout << "value of the string variable: " << str << std::endl;
    std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;    

    return 0;

}