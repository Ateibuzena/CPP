#include "Fixed.hpp"

std::ostream    &operator<<(std::ostream& fd, const Fixed& object)
{
    std::cout
        << "\nℹ️  Extern: Operator overload"
        << std::endl;
    
    fd << object.toFloat();
    
    return (fd);
}
