#include <iostream> //used for cin, cout
#include <string> //used for string class
#include <iomanip> //used for setw
#include <sstream> //used for isstringstream class


void ft_print_according_to_index(std::string &index_str, Phonebook &phonebook)
{
    std::istringstream iss;
    int index;

    iss.str(index_str);
    if (!(iss >> index))
    {
        std::cout << "Invalid input - not a number\n";
        return;
    }
    else
    {
        if (index >= 0 && index < phonebook.pb_size)
            phonebook.print_contact(index);
        else
        {
            std::cout << "Please enter a valid index between 0 and ";
            std::cout << phonebook.pb_size - 1 << std::endl;
        }
    }
}

void ft_print_search_headers() 
{
    std::cout << std::setw(10) << ft_truncate("index") << "|";
    std::cout << std::setw(10) << ft_truncate("first name") << "|";
    std::cout << std::setw(10) << ft_truncate("last name") << "|";
    std::cout << std::setw(10) << ft_truncate("nickname\n");
}

std::string ft_truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;

}

bool ft_isValidPN(std::string pn)
{
    int i(0);
    int len;

    len = pn.length();
    if (len != 9)
        return false;
    while (i < pn.length())
    {
        if (!isdigit(pn[i]))
            return false;
        i++;
    }
    return true;
}