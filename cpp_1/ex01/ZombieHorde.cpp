
#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name )
{
    Zombie* first_z = new Zombie[N];
    int i(0);

    while (i < N)
    {
        first_z[i].setName(name);
        i++;
    }
    return first_z;
}