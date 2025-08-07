#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB()
    :   _myName("Default name"),
        _myWeapon(NULL)
{
    std::cout
        << _myName
        << ": Default constructor"
        << std::endl;
}

HumanB::HumanB(const std::string& nameValue)
    :   _myName(nameValue),
        _myWeapon(NULL)
{
    std::cout
        << _myName
        << ": Parameterized constructor only name"
        << std::endl;
}

HumanB::HumanB(const std::string& nameValue, Weapon& weaponValue)
    :   _myName(nameValue),
        _myWeapon(&weaponValue)
{
    std::cout
        << _myName
        << ": Parameterized constructor with name and weapon"
        << std::endl;
}

HumanB::~HumanB()
{
    std::cout
        << _myName
        << ": Destructor"
        << std::endl;
}

void    HumanB::attack(void) const
{
    if (_myWeapon)
    {
        std::cout
        << _myName
        << " attacks with their "
        << _myWeapon->getType()
        << std::endl;
    }
    else
    {
        std::cout
        << _myName
        << " can't attack without weapon"
        << std::endl;
    }
}

void    HumanB::setName(const std::string& nameValue)
{
    _myName = nameValue;
    std::cout
        << _myName
        << ": Set name"
        << std::endl;
}

void    HumanB::setWeapon(Weapon& weaponValue)
{
    _myWeapon = &weaponValue;
    std::cout
        << _myName
        << ": Set weapon"
        << std::endl;
}

void    HumanB::unsetWeapon(void)
{
    _myWeapon = NULL;
    std::cout
        << _myName
        << ": Unset weapon"
        << std::endl;
}

const std::string&    HumanB::getName(void) const
{
    std::cout
        << _myName
        << ": Get name"
        << std::endl;
    return (_myName);
}

const Weapon*    HumanB::getWeapon(void) const
{
    if (_myWeapon)
    {
        std::cout
            << _myName
            << ": Get weapon"
            << std::endl;
        return (_myWeapon);
    }
    else
    {
        std::cout
            << _myName
            << ": Can't get weapon"
            << std::endl;
        return (NULL);
    }
}
