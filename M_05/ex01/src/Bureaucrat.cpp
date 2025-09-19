#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        throw GradeTooHighException(_name, _grade);
    if (_grade > 150)
        throw GradeTooLowException(_name, _grade);
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

/*-------------------------------SETTERS-------------------------------*/

/*void    Bureaucrat::setName(const std::string& nameValue)
{
    _name = nameValue;
}*/ //name is immutable

/*void    Bureaucrat::setGrade(int gradeValue)
{
    
}*/ //can't be set by the face

/*-------------------------------METHODS-------------------------------*/

void    Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < 1)
        throw GradeTooHighException(_name, _grade);
    _grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > 150)
        throw GradeTooLowException(_name, _grade);
    _grade++;
}

void    Bureaucrat::signForm(Form& object)
{
    try
    {
        object.beSigned(*this);
        std::cout
                << _name
                << " signed "
                << object.getName()
                << std::endl;
    }
    catch (const std::exception& error)
    {
        std::cout
                << _name
                << " couldn't sign "
                << object.getName()
                << " because:\n"
                << error.what()
                << std::endl;
    }
}

/*-------------------------------CLASSES-------------------------------*/

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name, int grade)
{
    std::ostringstream  oss;

    oss << "Bureaucrat: " << name
        << " grade " << grade
        << " is too high (cannot be less than 1)";

    _msg = oss.str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return (_msg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name, int grade)
{
    std::ostringstream  oss;

    oss << "Bureaucrat: " << name
        << " grade " << grade
        << " is too low (cannot be greater than 150)";

    _msg = oss.str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{

}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return (_msg.c_str());
}
