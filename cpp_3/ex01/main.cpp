
#include "ScavTrap.h"

int main(void)
{
    ScavTrap roomba;
    std::cout << "----------------\n";
    ClapTrap robot("CPP-03");
    std::cout << "-----------------\n";
    ScavTrap walle(roomba);
    std::cout << "-----------------\n";
    ScavTrap r2d2("r2d2");
    std::cout << "-----------------\n";
    std::cout << r2d2.getName() << ": ";
    std::cout << r2d2.getHitPoints() << " | " << r2d2.getEnergyPoints() << " | ";
    std::cout << r2d2.getDamage() << std::endl;
    std::cout << "--------------------\n";
    std::cout << roomba.getName() << std::endl;
    std::cout << walle.getName() << std::endl;
    std::cout << "--------------------\n";
    walle.setName("Walle");
    walle.attack("Norminette");
    robot.attack("Enemy Bot");
    std::cout << "-----------------\n";
    r2d2 = walle;
    std::cout << r2d2.getName() << std::endl;
    std::cout << "------------------\n";
    // roomba = robot; //not working because no overload for 2 diff classes
    roomba.beRepaired(3);
    std::cout << "-----------------\n";
    walle.takeDamage(10);
    std::cout << "-----------------\n";


    return 0;
}