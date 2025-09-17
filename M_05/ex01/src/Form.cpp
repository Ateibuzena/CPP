#include "Form.hpp"

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
    if (_writeGrade < 1)
        throw GradeTooHighException();
    if (_writeGrade > 150)
        throw GradeTooLowException();
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

}


Form::~Form()
{

}


const std::string&  Form::getName(void) const
{
    return (_name);
}

bool    Form::getSigned(void) const
{
    return (_signed);
}

const int   Form::getWriteGrade(void) const
{
    return (_writeGrade);
}

const int   Form::getExecuteGrade(void) const
{
    return (_executeGrade);
}

void    Form::beSigned(const Bureaucrat &object)
{
    if (object.getGrade() > _writeGrade)
        throw GradeTooLowException();
    _signed = true;
}