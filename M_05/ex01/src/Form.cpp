#include "Form.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Form::Form()
    :   _name("dafault name"),
        _writeGrade(0),
        _executeGrade(0),
        _signed(false)
{

}

Form::Form(const std::string& nameValue,
            int writeGradeValue,
            int executeGradeValue)
    :   _name(nameValue),
        _writeGrade(writeGradeValue),
        _executeGrade(executeGradeValue),
        _signed(false)
{
    if (_writeGrade < 1 || _executeGrade < 1)
        throw GradeTooHighException(_name, _writeGrade);
    if (_writeGrade > 150 || _executeGrade > 150)
        throw GradeTooLowException(_name, _writeGrade);
}

Form::Form(const Form& object)
    :   _name(object._name),
        _writeGrade(object._writeGrade),
        _executeGrade(object._executeGrade),
        _signed(object._signed)

{

}

Form&   Form::operator=(const Form& object)
{
    if (this != &object)
    {
        _signed = object._signed;
    }
    return (*this);
} //hasn't sense use it

/*-------------------------------DESTRUCTOR-------------------------------*/

Form::~Form()
{

}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  Form::getName(void) const
{
    return (_name);
}

bool    Form::getSigned(void) const
{
    return (_signed);
}

int   Form::getWriteGrade(void) const
{
    return (_writeGrade);
}

int   Form::getExecuteGrade(void) const
{
    return (_executeGrade);
}

/*-------------------------------SETTERS-------------------------------*/

/*void    Form::setName(const std::string& nameValue)
{

}*/ //name is immutable

/*void    Form::setWriteGrade(const int)
{

}*/ //writegrade is immutable

/*void    Form::setExecuteGrade(const int)
{

}*/ //executegrade is immutable

/*void    Form::setSigned(bool signedValue)
{

}*/ //can't be set by the face

/*-------------------------------METHODS-------------------------------*/

void    Form::beSigned(const Bureaucrat& object)
{
    if (object.getGrade() > _writeGrade)
        throw GradeTooLowException(_name, _writeGrade);
    _signed = true;
}

/*-------------------------------CLASSES-------------------------------*/

Form::GradeTooHighException::GradeTooHighException(const std::string& name, int writeGrade)
{
    std::ostringstream  oss;

    oss << "Form: " << name
        << " required grade " << writeGrade
        << " is too high (write or execute grade < 1)";

    _msg = oss.str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{

}

const char* Form::GradeTooHighException::what(void) const throw()
{
    return (_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string& name, int writeGrade)
{
    std::ostringstream  oss;

    oss << "Form: " << name
        << " required grade " << writeGrade
        << " is too low (write or execute grade > 150)";

    _msg = oss.str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{

}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return (_msg.c_str());
}