#include "WrongAnimal.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

WrongAnimal::WrongAnimal()
    :   _type("default type")
{
    /*std::cout
        << "\nWrongAnimal "
        << _type
        << " ℹ️ : Default constructor"
        << std::endl;*/
}

WrongAnimal::WrongAnimal(const std::string& typeValue)
    :   _type(typeValue)
{
    /*std::cout
        << "\nWrongAnimal "
        << _type
        << " ℹ️ : Parameterized constructor with type"
        << std::endl;*/
}

WrongAnimal::WrongAnimal(const WrongAnimal& object)
    :   _type(object._type)
{
    /*std::cout
        << "\nWrongAnimal "
        << _type
        << " ℹ️ : Copy constructor"
        << std::endl;*/
}

WrongAnimal&   WrongAnimal::operator=(const WrongAnimal& object)
{
    /*std::cout
        << "\nWrongAnimal "
        << _type
        << " ℹ️ : Operator assignement"
        << std::endl;*/
    
    if (this != &object)
    {
        _type = object._type;
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

WrongAnimal::~WrongAnimal()
{
    std::cout
        << "\nWrongAnimal "
        << _type
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  WrongAnimal::getType(void) const
{
    return (_type);
}

/*-------------------------------SETTERS-------------------------------*/

void    WrongAnimal::setType(const std::string& typeValue)
{
    _type = typeValue;
}

/*-------------------------------METHODS-------------------------------*/

void    WrongAnimal::makeSound(void) const
{
    std::cout
        << "\nWrongAnimal "
        << "default sound"
        << std::endl;
}