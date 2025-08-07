#include "Zombie.hpp"

Zombie* newZombie(const std::string& nameValue)
{
    Zombie*  heapZombie = new Zombie(nameValue);
    
    return (heapZombie);
}