#include "Fixed.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Fixed::Fixed()
    :   _rawBits(0),
        _copy(0)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Default constructor"
        << std::endl;*/
}

Fixed::Fixed(const int integer)
    :   _rawBits(integer << _bits), // cast integer to fixed point 
        _copy(0)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Parameterized constructor with an integer"
        << std::endl;*/
}

Fixed::Fixed(const float floatingPoint)
    :   _copy(0)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Parameterized constructor with a floating point"
        << std::endl;*/
    
    float   scaled = floatingPoint * (1 << _bits); 

    float   rounded = roundf(scaled);

    _rawBits = static_cast<int>(rounded);

}

Fixed::Fixed(const Fixed& object)
    :   _rawBits(object._rawBits),
        _copy(1)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Copy constructor"
        << std::endl;*/
}

Fixed&  Fixed::operator=(const Fixed& object)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator assignement"
        << std::endl;*/

    if (this != &object)
    {
        _rawBits = object._rawBits;
        _copy = 1;
    }
    
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

Fixed::~Fixed()
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Destructor"
        << std::endl;*/
}

/*-------------------------------COMPARISON OPERATORS-------------------------------*/

bool Fixed::operator<(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator less"
        << std::endl;*/
    
    int flag = 0;

    if (_rawBits < object._rawBits)
        flag = 1;
    
    return (flag);
}

bool Fixed::operator>(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator greater"
        << std::endl;*/

    int flag = 0;

    if (_rawBits > object._rawBits)
        flag = 1;
    
    return (flag);
}

bool Fixed::operator<=(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator less or equal"
        << std::endl;*/
        
    int flag = 0;

    if (_rawBits <= object._rawBits)
        flag = 1;
    
    return (flag);
}

bool Fixed::operator>=(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator greater or equal"
        << std::endl;*/

    int flag = 0;
    
    if (_rawBits >= object._rawBits)
        flag = 1;
    
    return (flag);
}

bool Fixed::operator==(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator equality"
        << std::endl;*/

    int flag = 0;

    if (_rawBits == object._rawBits)
        flag = 1;
    
    return (flag);
}

bool Fixed::operator!=(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator inequality"
        << std::endl;*/

    int flag = 0;

    if (_rawBits != object._rawBits)
        flag = 1;
    
    return (flag);
}

/*-------------------------------ARITHMETIC OPERATORS-------------------------------*/

Fixed   Fixed::operator+(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator addition"
        << std::endl;*/
    
    Fixed result;

    result._rawBits = _rawBits + object._rawBits;
    
    return (result);
}

Fixed   Fixed::operator-(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator subtraction"
        << std::endl;*/
    
    Fixed result;

    result._rawBits = _rawBits - object._rawBits;

    return (result);
}

Fixed   Fixed::operator*(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator multiplication"
        << std::endl;*/

    float   f = this->toFloat() * object.toFloat();
    Fixed   result = Fixed(f);
    
    return (result);
}

Fixed   Fixed::operator/(const Fixed& object) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator division"
        << std::endl;*/
    
    float   f = 0.0;

    if (object._rawBits == 0)
    {
        std::cout
            << "\n"
            << "Error: can't divide by 0"
            << std::endl;
    }
    else
        f = this->toFloat() / object.toFloat();

    Fixed result = Fixed(f);

    return (result);
}

/*-------------------------------OPERATORS-------------------------------*/

Fixed&   Fixed::operator++(void)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator pre-increment"
        << std::endl;*/

    _rawBits = _rawBits + 1;

    return (*this);
}

Fixed   Fixed::operator++(int)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator post-increment"
        << std::endl;*/
    
    Fixed result = *this;

    ++(*this);

    return (result);
}

Fixed&   Fixed::operator--(void)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator pre-drecrement"
        << std::endl;*/

    _rawBits = _rawBits - 1;

    return (*this);
}

Fixed   Fixed::operator--(int)
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Operator post-decrement"
        << std::endl;*/
    
    Fixed result = *this;

    --(*this);

    return (result);
}
/*-------------------------------UTILS-------------------------------*/

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a.toFloat() <= b.toFloat())
    {
        /*std::cout
            << "\n"
            << "ℹ️  a <= b"
            << std::endl;*/

        return (a);
    }
    else
    {
        /*std::cout
            << "\n"
            << "ℹ️  b < a"
            << std::endl;*/
        
        return (b);
    }
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.toFloat() <= b.toFloat())
    {
        /*std::cout
            << "\n"
            << "ℹ️  a <= b"
            << std::endl;*/

        return (a);
    }
    else
    {
        /*std::cout
            << "\n"
            << "ℹ️  b < a"
            << std::endl;*/
        
        return (b);
    }
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a.toFloat() >= b.toFloat())
    {
        /*std::cout
            << "\n"
            << "ℹ️  a >= b"
            << std::endl;*/

        return (a);
    }
    else
    {
        /*std::cout
            << "\n"
            << "ℹ️  b > a"
            << std::endl;*/
        
        return (b);
    }
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.toFloat() >= b.toFloat())
    {
        /*std::cout
            << "\n"
            << "ℹ️  a >= b"
            << std::endl;*/

        return (a);
    }
    else
    {
        /*std::cout
            << "\n"
            << "ℹ️  b > a"
            << std::endl;*/
        
        return (b);
    }
}

int   Fixed::toInt(void) const
{
    int desescaled = _rawBits >> _bits;
    
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : To int"
        << std::endl;*/
    
    return (desescaled);
}

float   Fixed::toFloat(void) const
{
    float   rawBits = static_cast<float>(_rawBits);
    float   desescaled = static_cast<float>(rawBits / (1 << _bits));
    
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : To float"
        << std::endl;*/
    
    return  (desescaled);
}

/*-------------------------------SETTERS-------------------------------*/

void    Fixed::setRawBits(const int rawBitsValue)
{
    _rawBits = rawBitsValue;

    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Set rawbits"
        << std::endl;*/
}

/*-------------------------------GETTERS-------------------------------*/

int Fixed::getRawBits(void) const
{
    /*std::cout
        << "\n"
        << _copy
        << " ℹ️ : Get rawbits"
        << std::endl;*/
    
    return (_rawBits);
}
