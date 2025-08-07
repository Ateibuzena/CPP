#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string& nameValue, Weapon& weaponValue)
    :   _myName(nameValue),
        _myWeapon(weaponValue)
{
    std::cout
        << _myName
        << ": Parameterized constructor with name and weapon"
        << std::endl;
}

HumanA::~HumanA()
{
    std::cout
        << _myName
        << ": Destructor"
        << std::endl;
}

void    HumanA::attack(void) const
{
    std::cout
        << _myName
        << " attacks with their "
        << _myWeapon.getType()
        << std::endl;
}

void    HumanA::setName(const std::string& nameValue)
{
    _myName = nameValue;
    std::cout
        << _myName
        << ": Set name"
        << std::endl;
}

const std::string&  HumanA::getName(void) const
{
    std::cout
        << _myName
        << ": Get name"
        << std::endl;
    return (_myName);
}

const Weapon&   HumanA::getWeapon(void) const
{
    std::cout
        << _myWeapon.getType()
        << ": Get weapon"
        << std::endl;
    return (_myWeapon);
}
