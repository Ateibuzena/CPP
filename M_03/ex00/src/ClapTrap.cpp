#include "ClapTrap.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

ClapTrap::ClapTrap()
    :   _name("default name"),
        _hit(10),
        _energy(10),
        _damage(0),
        _game(true)
{
    /*std::cout
        << "\n"
        << _name
        << " ℹ️ : Default constructor"
        << std::endl;*/
}

ClapTrap::ClapTrap(const std::string& nameValue)
    :   _name(nameValue),
        _hit(10),
        _energy(10),
        _damage(0),
        _game(true)
{
    /*std::cout
        << "\n"
        << _name
        << " ℹ️ : Parameterized constructor with name"
        << std::endl;*/
}

ClapTrap::ClapTrap(const ClapTrap& object)
    :   _name(object._name),
        _hit(object._hit),
        _energy(object._energy),
        _damage(object._damage),
        _game(true)
{
    /*std::cout
        << "\n"
        << _name
        << " ℹ️ : Copy constructor"
        << std::endl;*/
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& object)
{
    /*std::cout
        << "\n"
        << _name
        << " ℹ️ : Operator assignement"
        << std::endl;*/
    
    if (this != &object)
    {
        _name = object._name;
        _hit = object._hit;
        _energy = object._energy;
        _damage = object._damage;
        _game = object._game;
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

ClapTrap::~ClapTrap()
{
    std::cout
        << "\n"
        << _name
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  ClapTrap::getName(void) const
{
    return (_name);
}

const unsigned int&  ClapTrap::getHit(void) const
{
    return (_hit);
}

const unsigned int&  ClapTrap::getEnergy(void) const
{
    return (_energy);
}

const unsigned int&  ClapTrap::getDamage(void) const
{
    return (_damage);
}

bool  ClapTrap::getGame(void) const
{
    return (_game);
}

/*-------------------------------SETTERS-------------------------------*/

void    ClapTrap::setName(const std::string& nameValue)
{
    _name = nameValue;
}

void    ClapTrap::setHit(const int hitValue)
{
    _hit = hitValue;
}

void    ClapTrap::setEnergy(const int energyValue)
{
    _energy = energyValue;
}

void    ClapTrap::setDamage(const int damageValue)
{
    _damage = damageValue;
}

void    ClapTrap::setGame(const bool gameValue)
{
    _game = gameValue;
}

/*-------------------------------METHODS-------------------------------*/

void    ClapTrap::attack(const std::string& target)
{
    if (!_game)
    {
        std::cout
            << _name
            << " is out of combat"
            << std::endl;
        return ;
    }
    if (!_energy)
    {
        std::cout
            << _name
            << " can't attack"
            << std::endl;
        _game = false;
        return ;
    }
    _energy -= 1;

    std::cout
        << "\n"
        << _name
        << " attacks "
        << target
        << " causing "
        << _damage
        << " & now has "
        << _energy
        << " points of energy"
        << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (!_game)
    {
        std::cout
            << _name
            << " is out of combat"
            << std::endl;
        return ;
    }

    if (_hit > amount)
        _hit -= amount;
    else
        _hit = 0;

    std::cout
        << "\n"
        << _name
        << " recive "
        << amount
        << " points of damage"
        << std::endl;

    if (!_hit)
    {
        _game = false;
        std::cout
            << _name
            << " is out of combat"
            << std::endl;
        return ;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!_game)
    {
        std::cout
            << _name
            << " is out of combat"
            << std::endl;
        return ;
    }

    if (!_energy)
    {
        std::cout
            << _name
            << " can't be repaired"
            << std::endl;
        _game = false;
        return ;
    }
    _energy += 1;
    _hit += amount;

    std::cout
        << "\nClapTrap "
        << _name
        << " recive "
        << amount
        << " points of hit & now has "
        << _energy
        << " points of energy!"
        << std::endl;
}

void    ClapTrap::printState(void) const
{
    if (!_game)
    {
        std::cout
            << _name
            << " is out of combat"
            << std::endl;
        return ;
    }

    std::cout
        << "        Name: "
        <<  _name
        << "\n        Hit points: "
        << _hit
        << "\n        Energy points: "
        << _energy
        << "\n        Attack damage: "
        << _damage
        << std::endl;
}
