#include "Point.hpp"

int main( void )
{
    std::cout << "--------------------------TRIANGLE------------------------------" << std::endl;
    Point a(1.0f, 1.0f);
    Point b(10.0f, 1.0f);
    Point c(5.0f, 10.0f);

    std::cout << "--------------------------INSIDE------------------------------" << std::endl;
    Point p1(5.0f, 5.0f);

    std::cout << std::endl;
    std::cout << "p1 inside? " << std::endl;
    if (bsp(a, b, c, p1))
        std::cout << "\nYES" << std::endl;
    else
        std::cout << "\nNO" << std::endl;
    
    std::cout << std::endl;
    if (bsp(b, c, a, p1))
        std::cout << "\nYES" << std::endl;
    else
        std::cout << "\nNO" << std::endl;
    
    std::cout << std::endl;
    if (bsp(c, a, b, p1))
        std::cout << "\nYES" << std::endl;
    else
        std::cout << "\nNO" << std::endl;
    

    std::cout << "\n--------------------------OUTSIDE------------------------------" << std::endl;
    Point p2(5.0f, 11.0f);

    std::cout << std::endl;
    std::cout << "p2 inside? " << std::endl;
    if (bsp(a, b, c, p2))
        std::cout << "\nYES" << std::endl;
    else
        std::cout << "\nNO" << std::endl;
    

    std::cout << "\n--------------------------VERTEX------------------------------" << std::endl;
    Point p3(1.0f, 1.0f);

    std::cout << std::endl;
    std::cout << "p3 inside? " << std::endl;
    if (bsp(a, b, c, p3))
        std::cout << "\nYES" << std::endl;
    else
        std::cout << "\nNO" << std::endl;
    

    std::cout << "\n--------------------------EDGE------------------------------" << std::endl;
    Point p4(5.0f, 1.0f);

    std::cout << std::endl;
    std::cout << "p4 inside? " << std::endl;
    if (bsp(a, b, c, p4))
        std::cout << "\nYES" << std::endl;
    else
        std::cout << "\nNO" << std::endl;

    std::cout << "--------------------------DESTRUCTOR------------------------------" << std::endl;
    return (0);
}
