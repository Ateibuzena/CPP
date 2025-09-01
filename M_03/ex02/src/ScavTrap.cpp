#include "ScavTrap.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

ScavTrap::ScavTrap()
    :   ClapTrap(),
        _gateKeeper(false)
{
    std::cout
        << "\nScavTrap "
        << getName()
        << " ℹ️ : Default constructor"
        << std::endl;
    setHit(100);
    setEnergy(50);
    setDamage(20);
}

ScavTrap::ScavTrap(const std::string& nameValue)
    :   ClapTrap(nameValue),
        _gateKeeper(false)
{
    std::cout
        << "\nScavTrap "
        << getName()
        << " ℹ️ : Parameterized constructor with name"
        << std::endl;
    setHit(100);
    setEnergy(50);
    setDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& object)
    :   ClapTrap(object),
        _gateKeeper(object._gateKeeper)
{
    std::cout
        << "\nScavTrap "
        << getName()
        << " ℹ️ : Copy constructor"
        << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& object)
{
    std::cout
        << "\nScavTrap "
        << getName()
        << " ℹ️ : Operator assignement"
        << std::endl;
    
    if (this != &object)
    {
        /*setName(object.getName());
        setHit(object.getHit());
        setEnergy(object.getEnergy());
        setDamage(object.getDamage());
        setGame(object.getGame());*/

        /*ClapTrap::operator=(object);*/
        ClapTrap::operator=(static_cast<const ClapTrap&>(object));

        this->_gateKeeper = object._gateKeeper;
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

ScavTrap::~ScavTrap()
{
    std::cout
        << "\nScavTrap "
        << getName()
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/

bool        ScavTrap::getGateKeeper(void) const
{
    return (_gateKeeper);
}

/*-------------------------------SETTERS-------------------------------*/

void        ScavTrap::setGateKeeper(bool gateKeeperValue)
{
    _gateKeeper = gateKeeperValue;
}

/*-------------------------------METHODS-------------------------------*/

void    ScavTrap::attack(const std::string& target)
{
    if (!getGame())
    {
        std::cout
            << "\nScavTrap "
            << getName()
            << " is out of combat"
            << std::endl;
        return ;
    }
    if (!getEnergy())
    {
        std::cout
            << "\nScavTrap "
            << getName()
            << " can't attack"
            << std::endl;
        setGame(false);
        return ;
    }
    
    setEnergy(getEnergy() - 1);

    std::cout
        << "\nScavTrap "
        << getName()
        << " attacks "
        << target
        << " causing "
        << getDamage()
        << " & now has "
        << getEnergy()
        << " points of energy"
        << std::endl;
}

void    ScavTrap::guardGate(void)
{
    if (!getGame())
    {
        std::cout
            << "\nScavTrap "
            << getName()
            << " is out of combat"
            << std::endl;
        return ;
    }
    _gateKeeper = !_gateKeeper;

    if (_gateKeeper)
    {
        std::cout
        << "\nScavTrap "
        << getName()
        << " is now in Gate keeper mode"
        << std::endl;
    }
    else
    {
        std::cout
        << "\nScavTrap "
        << getName()
        << " isn't now in Gate keeper mode"
        << std::endl;
    }
    
}

void    ScavTrap::printState(void) const
{
    if (!getGame())
        return ;

    std::cout
        << "\n        ScavTrap\n"
        << "        Name: "
        << getName()
        << "\n        Hit points: "
        << getHit()
        << "\n        Energy points: "
        << getEnergy()
        << "\n        Attack damage: "
        << getDamage()
        << "\n        Keeper gate: "
        << this->_gateKeeper
        << std::endl;
}
