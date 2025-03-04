
#include "ClapTrap.h"

int main(void)
{
    ClapTrap robot("CPP-03");

    robot.attack("Enemy Bot");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10);
    robot.attack("Another Bot");
    robot.beRepaired(5);

    return 0;
}