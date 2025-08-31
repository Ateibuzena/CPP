#include "ScavTrap.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

ScavTrap::ScavTrap()
    :   ClapTrap(),
        _gateKeeper(false)
{
    std::cout
        << "\nScavTrap "
        << this->_name
        << " ℹ️ : Default constructor"
        << std::endl;
    _hit = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(const std::string& nameValue)
    :   ClapTrap(nameValue),
        _gateKeeper(false)
{
    std::cout
        << "\nScavTrap "
        << this->_name
        << " ℹ️ : Parameterized constructor with name"
        << std::endl;
    _hit = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& object)
    :   ClapTrap(object)
{
    std::cout
        << "\nScavTrap "
        << this->_name
        << " ℹ️ : Copy constructor"
        << std::endl;
    *this = object;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& object)
{
    std::cout
        << "\nScavTrap "
        << this->_name
        << " ℹ️ : Operator assignement"
        << std::endl;
    
    if (this != &object)
    {
        this->_name = object._name;
        this->_hit = object._hit;
        this->_energy = object._energy;
        this->_damage = object._damage;
        this->_gateKeeper = object._gateKeeper;
        this->_game = object._game;
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

ScavTrap::~ScavTrap()
{
    std::cout
        << "\nScavTrap "
        << this->_name
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------METHODS-------------------------------*/

void    ScavTrap::attack(const std::string& target)
{
    if (!this->_game)
    {
        std::cout
            << "\nScavTrap "
            << this->_name
            << " is out of combat"
            << std::endl;
        return ;
    }
    if (!this->_energy)
    {
        std::cout
            << "\nScavTrap "
            << this->_name
            << " can't attack"
            << std::endl;
        this->_game = false;
        return ;
    }
    this->_energy -= 1;

    std::cout
        << "\nScavTrap "
        << this->_name
        << " attacks "
        << target
        << " causing "
        << this->_damage
        << " & now has "
        << this->_energy
        << " points of energy"
        << std::endl;
}

void    ScavTrap::guardGate(void)
{
    if (!this->_game)
    {
        std::cout
            << "\nScavTrap "
            << this->_name
            << " is out of combat"
            << std::endl;
        return ;
    }
    _gateKeeper = !_gateKeeper;

    if (_gateKeeper)
    {
        std::cout
        << "\nScavTrap "
        << this->_name
        << " is now in Gate keeper mode"
        << std::endl;
    }
    else
    {
        std::cout
        << "\nScavTrap "
        << this->_name
        << " isn't now in Gate keeper mode"
        << std::endl;
    }
    
}

void    ScavTrap::printState(void) const
{
    if (!this->_game)
        return ;

    std::cout
        << "\n        ScavTrap\n"
        << "        Name: "
        <<  this->_name
        << "\n        Hit points: "
        << this->_hit
        << "\n        Energy points: "
        << this->_energy
        << "\n        Attack damage: "
        << this->_damage
        << "\n        Keeper gate: "
        << this->_gateKeeper
        << std::endl;
}
