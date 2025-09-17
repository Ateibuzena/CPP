#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Bureaucrat::Bureaucrat()
    :   _name("default name"),
        _grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string& nameValue, int gradeValue)
    :   _name(nameValue),
        _grade(gradeValue)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& object)
    :   _name(object._name),
        _grade(object._grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& object)
{
    if (this != &object)
    {
        /*_name = object._name;*/ //name is immutable
        _grade = object._grade;
    }

    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

Bureaucrat::~Bureaucrat()
{

}

/*-------------------------------GETTERS-------------------------------*/

const std::string&    Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

/*void    Bureaucrat::setName(const std::string& nameValue)
{
    _name = nameValue;
}*/ //name is immutable

/*-------------------------------SETTERS-------------------------------*/

void    Bureaucrat::setGrade(int gradeValue)
{
    if (_grade < 1)

    if (_grade > 150)

    _grade = gradeValue;
}

/*-------------------------------METHODS-------------------------------*/

void    Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

/*-------------------------------CLASSES-------------------------------*/

Bureaucrat::GradeTooHighException::GradeTooHighException()
{

}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{

}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low");
}
