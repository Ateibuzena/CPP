#include "Zombie.hpp"

void    randomChump(const std::string  nameValue)
{
    Zombie  stackZombie;

    stackZombie.setName(nameValue);
    std::string name = stackZombie.getName();
    std::cout << name << std::endl;
    stackZombie.announce();
}