#include "Zombie.hpp"

int main(void)
{
    {
        Zombie *heapZombie = newZombie("heapZombie");
    
        heapZombie->announce();
        delete heapZombie;
    }
    std::cout << "--------------------------------------" << std::endl;
    {
        randomChump("stackZombie");
    }
    std::cout << "--------------------------------------" << std::endl;
    {
        Zombie  defaultZombie;
        Zombie  parameterizedZombie = Zombie("parameterizedZombie");
        
        std::string name = parameterizedZombie.getName();
        defaultZombie.setName(name);
        defaultZombie.announce();
    }
    std::cout << "--------------------------------------" << std::endl;
}