#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

RobotomyRequestForm::RobotomyRequestForm()
    :   AForm(),
        _target("default target")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& targetValue)
    :   AForm("RobotomyRequestForm", 72, 45),
        _target(targetValue)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object)
    :   AForm(object),
        _target(object._target)
{

}

RobotomyRequestForm&   RobotomyRequestForm::operator=(const RobotomyRequestForm& object)
{
    if (this != &object)
    {
        _target = object._target;
    }
    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

RobotomyRequestForm::~RobotomyRequestForm()
{

}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  RobotomyRequestForm::getTarget(void) const
{
    return (_target);
}


/*-------------------------------SETTERS-------------------------------*/

void    RobotomyRequestForm::setTarget(const std::string& targetValue)
{
    _target = targetValue;
}

/*-------------------------------METHODS-------------------------------*/

void    RobotomyRequestForm::execute(const Bureaucrat& object) const
{
    if (!getSigned())
        throw AForm::GradeTooLowException(getName(), getExecuteGrade());
    
    if (object.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException(object.getName(), object.getGrade());

    std::cout
            << "RobotomyRequestForm: "
            << "* drilling noises *"
            << std::endl;

    static bool toggle = false;

    toggle = !toggle;
    if (toggle)
        std::cout
                << _target
                << " has been robotomized successfully"
                << std::endl;
    else
        std::cout
                << "Robotomy failed on "
                << _target
                << std::endl;
}
