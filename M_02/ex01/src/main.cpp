#include "Fixed.hpp"

int main( void )
{
    std::cout << a << std::endl;
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
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
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\nb is " << b.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\nc is " << c.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\nd is " << d.getRawBits() << " as fixed-point" << std::endl;
    
    std::cout << "-----------------------FLOAT------------------" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\nb is " << b.toFloat() << " as float" << std::endl;
    std::cout << "\nc is " << c.toFloat() << " as float" << std::endl;
    std::cout << "\nd is " << d.toFloat() << " as float" << std::endl;

    std::cout << "-----------------------INT------------------" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    std::cout << "\nb is " << b.toInt() << " as integer" << std::endl;
    std::cout << "\nc is " << c.toInt() << " as integer" << std::endl;
    std::cout << "\nd is " << d.toInt() << " as integer" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;

    return (0);
}