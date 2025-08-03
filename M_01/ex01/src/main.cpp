#include "Zombie.hpp"

int main(void)
{
    {
        int i = 0;
        int n = 10;
        Zombie* horde = zombieHorde(n, "Zombie");
        std::cout << "------------------------------" << std::endl;
        while (i < n)
        {
            horde[i].announce();
            i++;
        }
        std::cout << "------------------------------" << std::endl;
        deleteHorde(n, horde);
        std::cout << "------------------------------" << std::endl;
    }
}