#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    :   ClapTrap(),
        ScavTrap(),
        FragTrap(),
        _name("default diamond name")
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Default constructor"
        << std::endl;
    ScavTrap tempScav(static_cast<const ScavTrap&>(*this));
    static_cast<const ScavTrap&>(this)->setHit(static_cast<const ScavTrap&>(this)->getHit());
}

/*DiamondTrap::DiamondTrap(const std::string& nameValue)
    :   ClapTrap(nameValue + "_clap_name"),
        ScavTrap(),
        FragTrap(),
        _name(nameValue)
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Default constructor"
        << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& object)
    :   ClapTrap(object),
        _name("default diamond name")
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Parameterized constructor with name"
        << std::endl;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& object)
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Operator assignement"
        << std::endl;

    if (this != &object)
    {
        ClapTrap::operator=(static_cast<const ClapTrap&>(object));
        ScavTrap::operator=(static_cast<const ScavTrap&>(object));
        FragTrap::operator=(static_cast<const FragTrap&>(object));

        this->_name = object._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Destructor"
        << std::endl;
}

const std::string&  DiamondTrap::getName(void) const
{
    return (_name);
}

void    DiamondTrap::setName(const std::string& nameValue)
{
    _name = nameValue;
}

void    DiamondTrap::whoAmI()
{

}

void    DiamondTrap::printState(void) const
{
    if (!getGame())
        return ;

    std::cout
        << "\n        DiamondTrap\n"
        << "        Name: "
        <<  _name
        << "\n        Clap name: "
        <<  ClapTrap::getName()
        << "\n        Hit points: "
        << getHit()
        << "\n        Energy points: "
        << getEnergy()
        << "\n        Attack damage: "
        << getDamage()
        << "\n        Scav keeper gate: "
        << ScavTrap::getGateKeeper()
        << "\n        Frag keeper gate: "
        << FragTrap::getGateKeeper()
        << std::endl;
}*/