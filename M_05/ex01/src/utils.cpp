#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream&   operator<<(std::ostream& fd, const Bureaucrat& object)
{
    fd
        << object.getName()
        << ", grade: "
        << object.getGrade();
        
    return (fd);
}

std::ostream&   operator<<(std::ostream& fd, const Form& object)
{
    fd
        << object.getName()
        << "\nWrite grade: "
        << object.getWriteGrade()
        << "\nExecute grade: "
        << object.getExecuteGrade()
        << "\nSigned: "
        << object.getSigned();
        
    return (fd);
}