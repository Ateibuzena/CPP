#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

AForm::AForm()
    :   _name("dafault name"),
        _writeGrade(0),
        _executeGrade(0),
        _signed(false)
{

}

AForm::AForm(const std::string& nameValue,
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

AForm::AForm(const AForm& object)
    :   _name(object._name),
        _writeGrade(object._writeGrade),
        _executeGrade(object._executeGrade),
        _signed(object._signed)

{

}

AForm&   AForm::operator=(const AForm& object)
{
    if (this != &object)
    {
        _signed = object._signed;
    }
    return (*this);
} //hasn't sense use it

/*-------------------------------DESTRUCTOR-------------------------------*/

AForm::~AForm()
{

}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  AForm::getName(void) const
{
    return (_name);
}

bool    AForm::getSigned(void) const
{
    return (_signed);
}

int   AForm::getWriteGrade(void) const
{
    return (_writeGrade);
}

int   AForm::getExecuteGrade(void) const
{
    return (_executeGrade);
}

/*-------------------------------SETTERS-------------------------------*/

/*void    AForm::setName(const std::string& nameValue)
{

}*/ //name is immutable

/*void    AForm::setWriteGrade(const int)
{

}*/ //writegrade is immutable

/*void    AForm::setExecuteGrade(const int)
{

}*/ //executegrade is immutable

/*void    AForm::setSigned(bool signedValue)
{

}*/ //can't be set by the face

/*-------------------------------METHODS-------------------------------*/

void    AForm::beSigned(const Bureaucrat &object)
{
    if (object.getGrade() > _writeGrade)
        throw GradeTooLowException(_name, _writeGrade);
    _signed = true;
}

/*-------------------------------CLASSES-------------------------------*/

AForm::GradeTooHighException::GradeTooHighException(const std::string& name, int writeGrade)
{
    std::ostringstream  oss;

    oss << "AForm: " << name
        << " required grade " << writeGrade
        << " is too high (write or execute grade < 1)";

    _msg = oss.str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{

}

const char* AForm::GradeTooHighException::what(void) const throw()
{
    return (_msg.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& name, int writeGrade)
{
    std::ostringstream  oss;

    oss << "AForm: " << name
        << " required grade " << writeGrade
        << " is too low (write or execute grade > 150)";

    _msg = oss.str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{

}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return (_msg.c_str());
}