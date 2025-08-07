#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        std::cout << "----------------------------------------\n" << std::endl;

        HumanA bob("Bob", club);
        std::cout << "----------------------------------------\n" << std::endl;

        bob.attack();
        std::cout << "----------------------------------------\n" << std::endl;

        club.setType("some other type of club");
        std::cout << "----------------------------------------\n" << std::endl;
        
        bob.attack();
    }
    std::cout << "\n----------------------------------------\n" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        std::cout << "----------------------------------------\n" << std::endl;

        HumanB jim("Jim");
        std::cout << "----------------------------------------\n" << std::endl;

        jim.attack();
        std::cout << "----------------------------------------\n" << std::endl;

        jim.setWeapon(club);
        std::cout << "----------------------------------------\n" << std::endl;

        jim.attack();
        std::cout << "----------------------------------------\n" << std::endl;

        club.setType("some other type of club");
        std::cout << "----------------------------------------\n" << std::endl;

        jim.attack();
        std::cout << "----------------------------------------\n" << std::endl;

        jim.unsetWeapon();
        std::cout << "----------------------------------------\n" << std::endl;

        jim.attack();
        std::cout << "----------------------------------------\n" << std::endl;
    }
    return (0);
}