#include "Zombie.hpp"

int main(void)
{
    {
        int i = 0;
        int n = 10;
        Zombie* horde = zombieHorde(n, "Zombie");
        while (i < n)
        {
            std::cout << "------------------------------" << std::endl;
            horde[i].announce();
            i++;
        }
        deleteHorde(n, horde);
    }
}