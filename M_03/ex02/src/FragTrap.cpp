#include "FragTrap.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

FragTrap::FragTrap()
    :   ClapTrap()
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
    :   ClapTrap(nameValue)
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
    :   ClapTrap(object)
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
        << std::endl;
}
