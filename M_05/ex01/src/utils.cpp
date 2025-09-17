#include "Bureaucrat.hpp"

std::ostream&   operator<<(std::ostream& fd, const Bureaucrat& object)
{
    fd
        << object.getName()
        << ", grade: "
        << object.getGrade();
        
    return (fd);
}