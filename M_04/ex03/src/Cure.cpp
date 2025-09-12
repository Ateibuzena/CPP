#include "Cure.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Cure::Cure()
    :   AMateria()
{
    setType("💗");
}

Cure::Cure(const std::string& typeValue)
    :   AMateria(typeValue)
{

}

Cure::Cure(const Cure& object)
    :   AMateria(object)
{

}

Cure&   Cure::operator=(const Cure& object)
{
    if (this != &object)
    {
        AMateria::operator=(static_cast<const AMateria&>(object));
    }
    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

Cure::~Cure()
{

}

/*-------------------------------GETTERS-------------------------------*/



/*-------------------------------SETTERS-------------------------------*/



/*-------------------------------METHODS-------------------------------*/

AMateria*   Cure::clone() const //pure virtual from AMateria
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target) const
{
    std::cout
        << getType()
        << ": * heals "
        << target.getName()
        << "'s wounds *"
        << std::endl;
}
