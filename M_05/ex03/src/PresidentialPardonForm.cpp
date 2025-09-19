#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

PresidentialPardonForm::PresidentialPardonForm()
    :   AForm(),
        _target("default target")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& targetValue)
    :   AForm("PresidentialPardonForm", 25, 5),
        _target(targetValue)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object)
    :   AForm(object),
        _target(object._target)
{

}

PresidentialPardonForm&   PresidentialPardonForm::operator=(const PresidentialPardonForm& object)
{
    if (this != &object)
    {
        _target = object._target;
    }
    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm()
{

}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  PresidentialPardonForm::getTarget(void) const
{
    return (_target);
}


/*-------------------------------SETTERS-------------------------------*/

void    PresidentialPardonForm::setTarget(const std::string& targetValue)
{
    _target = targetValue;
}

/*-------------------------------METHODS-------------------------------*/

void    PresidentialPardonForm::execute(const Bureaucrat& object) const
{
    if (!getSigned())
        throw AForm::GradeTooLowException(getName(), getExecuteGrade());
    
    if (object.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException(object.getName(), object.getGrade());

    std::cout
            << "PresidentialPardonForm: "
            << _target
            << " officially pardoned by Zaphod Beeblebrox"
            << std::endl;
}
