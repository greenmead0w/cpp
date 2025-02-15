#include <iostream> //To use std namespace + cout/cin
#include <string>
#include <cctype>

//limitations: doesn't work on extended ascii or unicode characters (emojis or cyrilic chars, for example)

std::string ft_capitalize(char *c_string)
{
    std::string cpp_string = c_string; //alternative std::string cpp_string(c_string)
    int i = 0;
    while (i < cpp_string.length())
    {
        cpp_string[i] = std::toupper(cpp_string[i]); //part of cctype library
        i++;
    }
    return cpp_string;
}

void megaphone(int argc, char **argv)
{
    int i = 1;
    while(i < argc)
    {
        std::cout << ft_capitalize(argv[i]);
        // if (i < argc - 1)
        //     std::cout << ' ';
        i++;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    int i(0); //constructor initialization

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    megaphone(argc, argv);
    return (0);
}
