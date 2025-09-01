#include "FragTrap.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

FragTrap::FragTrap()
    :   ClapTrap(),
        _gateKeeper(false)
{
    std::cout
        << "\nFragTrap "
        << getName()
        << " ℹ️ : Default constructor"
        << std::endl;
    setHit(100);
    setEnergy(100);
    setDamage(30);
}

FragTrap::FragTrap(const std::string& nameValue)
    :   ClapTrap(nameValue),
        _gateKeeper(false)
{
    std::cout
        << "\nFragTrap "
        << getName()
        << " ℹ️ : Parameterized constructor with name"
        << std::endl;
    setHit(100);    // sobreescribes valores heredados
    setEnergy(100);
    setDamage(30);
}

FragTrap::FragTrap(const FragTrap& object)
    :   ClapTrap(object),
        _gateKeeper(false)
{
    std::cout
        << "\nFragTrap "
        << getName()
        << " ℹ️ : Copy constructor"
        << std::endl;
    *this = object;
}

FragTrap&   FragTrap::operator=(const FragTrap& object)
{
    std::cout
        << "\nFragTrap "
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

FragTrap::~FragTrap()
{
    std::cout
        << "\nFragTrap "
        << getName()
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/

bool        FragTrap::getGateKeeper(void) const
{
    return (_gateKeeper);
}

/*-------------------------------SETTERS-------------------------------*/

void        FragTrap::setGateKeeper(bool gateKeeperValue)
{
    _gateKeeper = gateKeeperValue;
}

/*-------------------------------METHODS-------------------------------*/

void    FragTrap::attack(const std::string& target)
{
    if (!getGame())
    {
        std::cout
            << "\nFragTrap "
            << getName()
            << " is out of combat"
            << std::endl;
        return ;
    }
    if (!getEnergy())
    {
        std::cout
            << "\nFragTrap "
            << getName()
            << " can't attack"
            << std::endl;
        setGame(false);
        return ;
    }

    setEnergy(getEnergy() - 1);

    std::cout
        << "\nFragTrap "
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

void FragTrap::highFivesGuys(void)
{
    std::cout
        << "\nFragTrap "
        << getName()
        << " requests a positive high five 🙌"
        << std::endl;
}

void    FragTrap::guardGate(void)
{
    if (!getGame())
    {
        std::cout
            << "\nFragTrap "
            << getName()
            << " is out of combat"
            << std::endl;
        return ;
    }
    _gateKeeper = !_gateKeeper;

    if (_gateKeeper)
    {
        std::cout
        << "\nFragTrap "
        << getName()
        << " is now in Gate keeper mode"
        << std::endl;
    }
    else
    {
        std::cout
        << "\nFragTrap "
        << getName()
        << " isn't now in Gate keeper mode"
        << std::endl;
    }
    
}

void    FragTrap::printState(void) const
{
    if (!getGame())
        return ;

    std::cout
        << "\n        FragTrap\n"
        << "        Name: "
        <<  getName()
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
