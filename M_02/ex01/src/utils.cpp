#include "Fixed.hpp"

std::ostream    &operator<<(std::ostream& fd, const Fixed& object)
{
    fd << object.toFloat();
    
    return (fd);
}
