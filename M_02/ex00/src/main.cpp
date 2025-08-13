
#include "Fixed.hpp"

int main(void)
{
    {
        std::cout << "--------------------A---------------------" << std::endl;
        Fixed a;

        std::cout << "--------------------B---------------------" << std::endl;
        Fixed b(a);

        std::cout << "--------------------C---------------------" << std::endl;
        Fixed c;

        std::cout << "-----------------------------------------" << std::endl;
        c = b;

        std::cout << "---------------------GET--------------------" << std::endl;
        std::cout << a.getRawBits() << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << c.getRawBits() << std::endl;

        std::cout << "---------------------SET--------------------" << std::endl;
        a.setRawBits(10);
        std::cout << "-----------------------------------------" << std::endl;
        b.setRawBits(11);
        std::cout << "-----------------------------------------" << std::endl;
        c.setRawBits(12);

        std::cout << "---------------------GET--------------------" << std::endl;
        std::cout << a.getRawBits() << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << c.getRawBits() << std::endl;
    }
    
    return (0);
}
