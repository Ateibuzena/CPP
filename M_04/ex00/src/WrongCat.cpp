#include "WrongCat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

WrongCat::WrongCat()
    :   WrongAnimal("WrongCat")
{
    /*std::cout
        << "\nWrongCat "
        << getType()
        << " ℹ️ : Default constructor"
        << std::endl;*/
}

WrongCat::WrongCat(const std::string& typeValue)
    :   WrongAnimal(typeValue)
{
    /*std::cout
        << "\nWrongCat "
        << getType()
        << " ℹ️ : Parameterized constructor with type"
        << std::endl;*/
}

WrongCat::WrongCat(const WrongCat& object)
    :   WrongAnimal(object)
{
    /*std::cout
        << "\nWrongCat "
        << getType()
        << " ℹ️ : Copy constructor"
        << std::endl;*/
}

WrongCat&   WrongCat::operator=(const WrongCat& object)
{
    /*std::cout
        << "\nWrongCat "
        << getType()
        << " ℹ️ : Operator assignement"
        << std::endl;*/
    
    if (this != &object)
    {
        /*setType(object.getType());*/

        /*WrongAnimal::operator=(object);*/
        WrongAnimal::operator=(static_cast<const WrongAnimal&>(object));
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

WrongCat::~WrongCat()
{
    std::cout
        << "\nWrongCat "
        << getType()
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/



/*-------------------------------SETTERS-------------------------------*/



/*-------------------------------METHODS-------------------------------*/

void    WrongCat::makeSound(void) const
{
    std::cout
        << "\nWrongCat "
        << "miau miau"
        << std::endl;
}