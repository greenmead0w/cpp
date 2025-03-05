
#include "ClapTrap.h"

int main(void)
{
    ClapTrap roomba;
    ClapTrap robot("CPP-03");

    robot.attack("Enemy Bot");
    roomba = robot;
    roomba.beRepaired(3);
    robot.takeDamage(10);
    

    return 0;
}