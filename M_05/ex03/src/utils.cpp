#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream&   operator<<(std::ostream& fd, const Bureaucrat& object)
{
    fd
        << object.getName()
        << ", grade: "
        << object.getGrade();
        
    return (fd);
}

std::ostream&   operator<<(std::ostream& fd, const AForm& object)
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