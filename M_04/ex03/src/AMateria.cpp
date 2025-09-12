#include "AMateria.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

AMateria::AMateria()
    :   _type("defautl type")
{

}

AMateria::AMateria(const std::string& typeValue)
    :   _type(typeValue)
{

}

AMateria::AMateria(const AMateria& object)
    :   _type(object._type)
{

}

AMateria&   AMateria::operator=(const AMateria& object)
{
    if (this != &object)
    {
        _type = object._type;
    }
    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

AMateria::~AMateria()
{

}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  AMateria::getType(void) const
{
    return (_type);
}

/*-------------------------------SETTERS-------------------------------*/

void    AMateria::setType(const std::string& typeValue)
{
    _type = typeValue;
}

/*-------------------------------METHODS-------------------------------*/

void    AMateria::use(ICharacter& target) const
{
    std::cout
        << "default message of the materia use to "
        << target.getName()
        << std::endl;
}
