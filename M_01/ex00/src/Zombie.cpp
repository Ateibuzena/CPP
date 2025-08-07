#include "Zombie.hpp"

Zombie::Zombie()
    :   _name("Default name")
{
    std::cout
    << _name
    << ": Default constructor"
    << std::endl;
}

Zombie::~Zombie()
{
    std::cout
    << _name
    << ": Destructor"
    << std::endl;
}

Zombie::Zombie(const std::string& nameValue)
    :   _name(nameValue)
{
    std::cout
        << _name
        << ": Parameterized constructor"
        << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout
        << _name
        << ": BraiiiiiiinnnzzzZ..."
        << std::endl;
}

void    Zombie::setName(const std::string& nameValue)
{
    _name = nameValue;
    std::cout
        << _name
        << ": Set Name"
        << std::endl;
}


const std::string&    Zombie::getName(void) const
{
    std::cout
        << _name
        << ": Get Name"
        << std::endl;
    return (_name);
}
