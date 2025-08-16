#include "Fixed.hpp"


int main( void )
{
    std::cout << "-----------------------A------------------" << std::endl;
    Fixed a;
    a = Fixed(1234.4321f);
    
    std::cout << "-----------------------B------------------" << std::endl;
    Fixed const b(10);
    
    std::cout << "-----------------------C------------------" << std::endl;
    Fixed const c(42.42f);
    
    std::cout << "-----------------------D------------------" << std::endl;
    Fixed const d(b);

    std::cout << "-----------------------FIXED-POINT------------------" << std::endl;
    std::cout << "a is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "b is " << b.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "c is " << c.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "d is " << d.getRawBits() << " as fixed-point" << std::endl;
    
    std::cout << "-----------------------FLOAT------------------" << std::endl;
    std::cout << "a is " << a << " as float" << std::endl;
    std::cout << "b is " << b << " as float" << std::endl;
    std::cout << "c is " << c << " as float" << std::endl;
    std::cout << "d is " << d << " as float" << std::endl;

    std::cout << "-----------------------INT------------------" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;

    return (0);
}