#include "Animal.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Animal::Animal()
    :   _type("default type"),
        _brain(new Brain())
{
    std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Default constructor"
        << std::endl;
}

Animal::Animal(const std::string& typeValue, const Brain& brainValue)
    :   _type(typeValue),
        _brain(new Brain(brainValue))
{
    std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Parameterized constructor with type"
        << std::endl;
}

Animal::Animal(const Animal& object)
    :   _type(object._type),
        _brain(new Brain(*object._brain))
{
    std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Copy constructor"
        << std::endl;
}

Animal&   Animal::operator=(const Animal& object)
{
    std::cout
        << "\nAnimal "
        << _type
        << " ℹ️ : Operator assignement"
        << std::endl;
    
    if (this != &object)
    {
        _type = object._type;

        /*delete _brain;
        _brain = new Brain(*object._brain);*/
        *_brain = *object._brain;
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

Animal::~Animal()
{
    delete _brain;

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

const Brain&    Animal::getBrain(void) const
{
    return (*_brain);
}

/*-------------------------------SETTERS-------------------------------*/

void    Animal::setType(const std::string& typeValue)
{
    _type = typeValue;
}

void    Animal::setBrain(const Brain& brainValue)
{
    /*delete _brain;
    _brain = new Brain(*brainValue);*/
    *_brain = brainValue;
}

/*-------------------------------METHODS-------------------------------*/

void    Animal::makeSound(void) const
{
    std::cout
        << "\nAnimal "
        << "default sound"
        << std::endl;
}