#include "Animal.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Animal::Animal()
    :   _type("default type")
{
    /*std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Default constructor"
        << std::endl;*/
}

Animal::Animal(const std::string& typeValue)
    :   _type(typeValue)
{
    /*std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Parameterized constructor with type"
        << std::endl;*/
}

Animal::Animal(const Animal& object)
    :   _type(object._type)
{
    /*std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Copy constructor"
        << std::endl;*/
}

Animal&   Animal::operator=(const Animal& object)
{
    /*std::cout
        << "\nAnimal "
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

Animal::~Animal()
{
    std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  Animal::getType(void) const
{
    return (_type);
}

/*-------------------------------SETTERS-------------------------------*/

void    Animal::setType(const std::string& typeValue)
{
    _type = typeValue;
}

/*-------------------------------METHODS-------------------------------*/

void    Animal::makeSound(void) const
{
    std::cout
        << "\nAnimal "
        << "default sound"
        << std::endl;
}