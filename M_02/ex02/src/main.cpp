#include "Fixed.hpp"

int main( void )
{
    std::cout << "--------------------------A------------------------------" << std::endl;
    
    Fixed a;
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << a << std::endl;
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << ++a << std::endl;
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << a << std::endl;
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << a++ << std::endl;
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << a << std::endl;
    std::cout << "\na is " << a.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;

    std::cout << "\n--------------------------B------------------------------" << std::endl;

    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "\nb is " << b.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\nb is " << b.toFloat() << " as float" << std::endl;
    std::cout << "\nb is " << b.toInt() << " as integer" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << b << std::endl;
    std::cout << "\nb is " << b.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\nb is " << b.toFloat() << " as float" << std::endl;
    std::cout << "\nb is " << b.toInt() << " as integer" << std::endl;

    std::cout << "\n--------------------------RESULT------------------------------" << std::endl;
    
    const Fixed&  result = Fixed::max(a, b);
    std::cout << result << std::endl;
    std::cout << "\nResult is " << result.getRawBits() << " as fixed-point" << std::endl;
    std::cout << "\nResult is " << result.toFloat() << " as float" << std::endl;
    std::cout << "\nResult is " << result.toInt() << " as integer" << std::endl;

    std::cout << "\n--------------------------DESTRUCTOR------------------------------" << std::endl;

    return (0);
}