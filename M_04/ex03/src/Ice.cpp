#include "Ice.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Ice::Ice()
    :   AMateria()
{
    setType("🧊");
}

Ice::Ice(const std::string& typeValue)
    :   AMateria(typeValue)
{

}

Ice::Ice(const Ice& object)
    :   AMateria(object)
{

}

Ice&   Ice::operator=(const Ice& object)
{
    if (this != &object)
    {
        AMateria::operator=(static_cast<const AMateria&>(object));
    }
    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

Ice::~Ice()
{

}

/*-------------------------------GETTERS-------------------------------*/



/*-------------------------------SETTERS-------------------------------*/



/*-------------------------------METHODS-------------------------------*/

AMateria*   Ice::clone() const //pure virtual from AMateria
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target) const
{
    std::cout
        << getType()
        << ": * shoots an ice bolt at "
        << target.getName()
        << " *"
        << std::endl;
}
