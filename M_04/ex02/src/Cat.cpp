#include "Cat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Cat::Cat()
    :   Animal()
{
    setType("Cat");

    std::cout
        << "\nCat "
        << getType()
        << " ℹ️ : Default constructor"
        << std::endl;
}

Cat::Cat(const std::string& typeValue, const Brain& brainValue)
    :   Animal(typeValue, brainValue)
{
    std::cout
        << "\nCat "
        << getType()
        << " ℹ️ : Parameterized constructor with type"
        << std::endl;
}

Cat::Cat(const Cat& object)
    :   Animal(object)
{
    std::cout
        << "\nCat "
        << getType()
        << " ℹ️ : Copy constructor"
        << std::endl;
}

Cat&   Cat::operator=(const Cat& object)
{
    std::cout
        << "\nCat "
        << getType()
        << " ℹ️ : Operator assignement"
        << std::endl;
    
    if (this != &object)
    {
        /*setType(object.getType());*/

        /*Animal::operator=(object);*/
        Animal::operator=(static_cast<const Animal&>(object));
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

Cat::~Cat()
{
    std::cout
        << "\nCat "
        << getType()
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/



/*-------------------------------SETTERS-------------------------------*/



/*-------------------------------METHODS-------------------------------*/

void    Cat::makeSound(void) const
{
    std::cout
        << "\nCat "
        << "miau miau"
        << std::endl;
}