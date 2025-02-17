
#include "Zombie.hpp"

int main(void)
{
    Zombie *zHorde;
    int n(4); //modify to test on eval (ADD user input?)
    int i(0);

    zHorde = zombieHorde(n, "Horde"); //name can be modified to test
    while (i < n)
    {
        zHorde[i].announce();
        i++;
    }
    delete [] zHorde;
}