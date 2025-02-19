
#include "Harl.hpp"
#include <iostream>

void Harl::debug( void )
{
    std::cout << "This is a debug message.\n";
}

void Harl::info( void )
{
    std::cout << "This is an info message.\n";
}

void Harl::warning( void )
{
    std::cout << "This is a warning message.\n";
}

void Harl::error( void )
{
    std::cout << "This is an error message.\n";
}

void Harl::complain( std::string level )
{
    int i(0);

    std::string msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*ptr[4]) (void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    while(i < 4)
    {
        if(level == msg[i])
        {
            (this->*ptr[i])();
            return ;
        }
        i++;
    }

    std::cout << "No match found\n";

}