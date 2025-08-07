#include "Zombie.hpp"

int main(void)
{
    std::cout << "\n------------------HEAP--------------------\n" << std::endl;
    {
        Zombie *heapZombie = newZombie("heapZombie");
        std::cout << "--------------------------------------" << std::endl;

        heapZombie->announce();
        std::cout << "--------------------------------------" << std::endl;

        delete heapZombie;
    }
    std::cout << "\n------------------STACK FUNCTION--------------------\n" << std::endl;
    {
        randomChump("stackZombie");
    }
    std::cout << "\n-------------------STACK MAIN-------------------\n" << std::endl;
    {
        Zombie  defaultZombie;
        std::cout << "--------------------------------------" << std::endl;
        Zombie  parameterizedZombie = Zombie("parameterizedZombie");
        std::cout << "--------------------------------------" << std::endl;
        
        std::string name = parameterizedZombie.getName();
        std::cout << "--------------------------------------" << std::endl;

        std::cout
            << defaultZombie.getName()
            << std::endl;
        std::cout << "--------------------------------------" << std::endl;

        defaultZombie.setName(name);
        std::cout << "--------------------------------------" << std::endl;
        defaultZombie.announce();
        std::cout << "--------------------------------------" << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
}