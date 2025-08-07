#include "Weapon.hpp"


Weapon::Weapon()
    :   _type("Default weapon")
{
    std::cout
        << _type
        << ": Default constructor"
        << std::endl;
}

Weapon::Weapon(const std::string& typeValue)
    :   _type(typeValue)
{
    std::cout
        << _type
        << ": Parameterized constructor"
        << std::endl;
}

Weapon::~Weapon()
{
    std::cout
        << _type
        << ": Destructor"
        << std::endl;
}

void    Weapon::setType(const std::string& typeValue)
{
    _type = typeValue;
    std::cout
        << _type
        << ": Set type"
        << std::endl;
}

const std::string&  Weapon::getType(void) const
{
    std::cout
        << _type
        << ": Get type"
        << std::endl;
    return (_type);
}
