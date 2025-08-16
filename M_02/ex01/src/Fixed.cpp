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

Fixed::Fixed(const int integer)
    :   _rawBits(integer << _bits), // cast integer to fixed point 
        _copy(0)
{
    std::cout
        << _copy
        << ": Parameterized constructor with an integer"
        << std::endl;
}

Fixed::Fixed(const float floatingPoint)
    :   _copy(0)
{
    float   scaled = floatingPoint * (1 << _bits); 

    float   rounded = roundf(scaled);

    _rawBits = static_cast<int>(rounded);

    std::cout
        << _copy
        << ": Parameterized constructor with a floating point"
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

int   Fixed::toInt(void) const
{
    int desescaled = _rawBits >> _bits;

    std::cout
        << _copy
        << ": To int"
        << std::endl;
    
    return (desescaled);
}

float   Fixed::toFloat(void) const
{
    float   rawBits = static_cast<float>(_rawBits);
    float   desescaled = static_cast<float>(rawBits / (1 << _bits));

    std::cout
        << _copy
        << ": To float"
        << std::endl;

    return  (desescaled);
}
