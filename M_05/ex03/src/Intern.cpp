#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm*  (*FormConstructor)(const std::string& target);

Intern::Intern()
{

}

/*Intern::Intern();
{

}*/

Intern::Intern(const Intern& object)
{
    (void)object;
}

Intern& Intern::operator=(const Intern& object)
{
    (void)object;
    
    return (*this);
}

Intern::~Intern()
{

}

static AForm*   makeShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm*   makeRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

static AForm*   makePresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string forms[3] = {
                            "shrubbery creation",
                            "robotomy request",
                            "presidential pardon"
                            };

    FormConstructor constructors[3];
    constructors[0] = &makeShrubbery;
    constructors[1] = &makeRobotomy;                          
    constructors[2] = &makePresidential;

    int i = 0;
    while (i < 3)
    {
        if (formName == name[i])
        {
            std::cout
                    << "Intern creates "
                    << formName
                    << std::endl;
            return (constructors[i]);
        }
        i++;
    }

    std::cout
            << "Intern couldn't find the form: "
            << formName
            << std::endl;
    return (NULL);
}
