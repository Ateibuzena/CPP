#include "Fixed.hpp"

Fixed::Fixed()
    :   _rawBits(0),
        _copy(0)
{
    std::cout
        << _copy
        << ": Default constructor"
        << std::endl;
}

Fixed::Fixed(const Fixed& object)
    :   _rawBits(object._rawBits),
        _copy(1)
{
    std::cout
        << _copy
        << ": Copy constructor"
        << std::endl;
}

Fixed::~Fixed()
{
    std::cout
        << _copy
        << ": Destructor"
        << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& object)
{
    if (this != &object)
    {
        _rawBits = object._rawBits;
        _copy = 1;
    }
    std::cout
        << _copy
        << ": Operator assignement"
        << std::endl;
    return (*this);
}

void    Fixed::setRawBits(const int rawBitsValue)
{
    _rawBits = rawBitsValue;
    std::cout
        << _copy
        << ": Set rawbits"
        << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout
        << _copy
        << ": Get rawbits"
        << std::endl;
    return (_rawBits);
}
