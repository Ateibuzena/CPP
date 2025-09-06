#include "DiamondTrap.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

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
    setHit(100); //like fragtrap
    setEnergy(50); //like scavtrap
    setDamage(30); //like fragtrap
}

DiamondTrap::DiamondTrap(const std::string& nameValue)
    :   ClapTrap(nameValue + "_clap_name"),
        ScavTrap(nameValue + "_scav_name"),
        FragTrap(nameValue + "_frag_name"),
        _name(nameValue)
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Parameterized constructor with name"
        << std::endl;
    setHit(100); //like fragtrap
    setEnergy(50); //like scavtrap
    setDamage(30); //like fragtrap
}

DiamondTrap::DiamondTrap(const DiamondTrap& object)
    :   ClapTrap(object),
        ScavTrap(object),
        FragTrap(object),
        _name(object._name)
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Copy constructor"
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

/*-------------------------------DESTRUCTORS-------------------------------*/

DiamondTrap::~DiamondTrap()
{
    std::cout
        << "\nDiamondTrap "
        << getName()
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  DiamondTrap::getName(void) const
{
    return (_name);
}

/*-------------------------------SETTERS-------------------------------*/

void    DiamondTrap::setName(const std::string& nameValue)
{
    _name = nameValue;
}

/*-------------------------------METHODS-------------------------------*/

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "\n🆔 DiamondTrap identity:" << std::endl;

    // Comparación entre nombres
    // Compare DiamondTrap's private name with ClapTrap's name
    std::cout << "  DiamondTrap::_name = " << this->_name << std::endl;
    std::cout << "  ClapTrap::_name    = " << ClapTrap::getName() << std::endl;
    if (this->_name == ClapTrap::getName())
        std::cout << "   👉 Same name" << std::endl;
    else
        std::cout << "   👉 Different names" << std::endl;

    // Comparación de atributos base
    // Compare ClapTrap attributes (overridden by daughters' defaults)
    std::cout << "  Hit points   = " << getHit()
              << " (should match FragTrap default: 100)" << std::endl;
    std::cout << "  Energy points= " << getEnergy()
              << " (should match ScavTrap default: 50)" << std::endl;
    std::cout << "  Attack dmg   = " << getDamage()
              << " (should match FragTrap default: 30)" << std::endl;

    // Extra de ScavTrap
    // Extra ScavTrap-specific state
    std::cout << "  ScavTrap::gateKeeper = " << ScavTrap::getGateKeeper() << std::endl;

    // Recordatorio de métodos disponibles
    // Methods explicitly inherited from both parents
    std::cout << "  FragTrap provides: highFivesGuys()" << std::endl;
    std::cout << "  ScavTrap provides: guardGate(), attack()" << std::endl;
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
        << std::endl;
}