#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm()
    :   AForm(),
        _target("default target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& targetValue)
    :   AForm("ShrubberyCreationForm", 145, 137),
        _target(targetValue)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object)
    :   AForm(object),
        _target(object._target)
{

}

ShrubberyCreationForm&   ShrubberyCreationForm::operator=(const ShrubberyCreationForm& object)
{
    if (this != &object)
    {
        _target = object._target;
    }
    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  ShrubberyCreationForm::getTarget(void) const
{
    return (_target);
}


/*-------------------------------SETTERS-------------------------------*/

void    ShrubberyCreationForm::setTarget(const std::string& targetValue)
{
    _target = targetValue;
}

/*-------------------------------METHODS-------------------------------*/

void    ShrubberyCreationForm::execute(const Bureaucrat& object) const
{
    if (!getSigned())
        throw AForm::GradeTooLowException(getName(), getExecuteGrade());
    
    if (object.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException(object.getName(), object.getGrade());

    std::string fileName;
    fileName = _target + "_shrubbery";

    std::ofstream outfile(fileName.c_str());
    if (!outfile)
    {
        std::cerr
                << "Error: could not create file "
                << fileName
                << std::endl;
        return ;
    }

    outfile << "        _-_\n";
    outfile << "     /~~   ~~\\\n";
    outfile << "  /~~         ~~\\\n";
    outfile << " {               }\n";
    outfile << "  \\  _-     -_  /\n";
    outfile << "    ~  \\\\ //  ~\n";
    outfile << "_- -   | | _- _\n";
    outfile << "  _ -  | |   -_\n";
    outfile << "      // \\\\\n";
    outfile << "     ||   ||\n";
    outfile << "     ||   ||\n";
    outfile << "     ||   ||\n";

    outfile.close();

    std::cout
            << "ShrubberyCreationForm:\nAuthorization to plant trees in "
            << _target
            << " kept in "
            << fileName
            << std::endl;
}
