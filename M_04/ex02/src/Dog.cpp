#include "Dog.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Dog::Dog()
    :   Animal()
{
    setType("Dog");

    std::cout
        << "\nDog "
        << getType()
        << " ℹ️ : Default constructor"
        << std::endl;
}

Dog::Dog(const std::string& typeValue, const Brain& brainValue)
    :   Animal(typeValue, brainValue)
{
    std::cout
        << "\nDog "
        << getType()
        << " ℹ️ : Parameterized constructor with type"
        << std::endl;
}

Dog::Dog(const Dog& object)
    :   Animal(object)
{
    std::cout
        << "\nDog "
        << getType()
        << " ℹ️ : Copy constructor"
        << std::endl;
}

Dog&   Dog::operator=(const Dog& object)
{
    std::cout
        << "\nDog "
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

Dog::~Dog()
{
    std::cout
        << "\nDog "
        << getType()
        << " ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/



/*-------------------------------SETTERS-------------------------------*/



/*-------------------------------METHODS-------------------------------*/

void    Dog::makeSound(void) const
{
    std::cout
        << "\nDog "
        << "guau guau"
        << std::endl;
}