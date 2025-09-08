#include "Brain.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Brain::Brain()
{
    std::fill(_ideas, _ideas + 100, "empty");

    std::cout
        << "\nBrain "
        << _ideas[0]
        << " ℹ️ : Default constructor"
        << std::endl;
}

Brain::Brain(const std::string (&ideasValue)[100])
{
    std::copy(ideasValue, ideasValue + 100, _ideas);

    std::cout
        << "\nBrain "
        << _ideas[0]
        << " ℹ️ : Parameterized constructor with ideas"
        << std::endl;
}

Brain::Brain(const Brain& object)
{
    std::copy(object._ideas, object._ideas + 100, _ideas);
    
    std::cout
        << "\nBrain "
        << _ideas[0]
        << " ℹ️ : Copy constructor"
        << std::endl;
}

Brain&  Brain::operator=(const Brain& object)
{
    if (this != &object)
    {
        std::copy(object._ideas, object._ideas + 100, _ideas);
    }

    std::cout
        << "\nBrain "
        << _ideas[0]
        << " ℹ️ : Operator assignement"
        << std::endl;
    
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

Brain::~Brain()
{
    std::cout
        << "\nBrain "
        << _ideas[0]
        << " ℹ️ : Destructor"
        << std::endl;
}  

/*-------------------------------GETTERS-------------------------------*/

const std::string   (&Brain::getIdeas(void) const)[100]
{
    return (_ideas);
}

/*-------------------------------SETTERS-------------------------------*/

void    Brain::setIdeas(const std::string (&ideasValue)[100])
{
    std::copy(ideasValue, ideasValue + 100, _ideas);
}

/*-------------------------------METHODS-------------------------------*/