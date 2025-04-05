
#include <iostream>
int main(void)
{
    //set precision 1
    char num = '1';
    std::cout << "float: " << static_cast<float>(num) << std::endl;
    std::cout << "char: " << static_cast<char>(num) << std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
    return 0;

}