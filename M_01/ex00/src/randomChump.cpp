#include "Zombie.hpp"

void    randomChump(const std::string&  nameValue)
{
    Zombie  stackZombie;

    stackZombie.setName(nameValue);
    std::cout << "--------------------------------------" << std::endl;
    std::string name = stackZombie.getName();
    std::cout << "--------------------------------------" << std::endl;
    std::cout
        << name
        << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    stackZombie.announce();
    std::cout << "--------------------------------------" << std::endl;
}