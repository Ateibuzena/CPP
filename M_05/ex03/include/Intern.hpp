#ifndef INTERN_HP
# define INTERN_HP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
    public:
                Intern();
                //Intern(); //parametrize constructor
                Intern(const Intern& object);
        Intern& operator=(const Intern& object);
                ~Intern();

        AForm*  makeForm(const std::string& formName, const std::string& target);
}