#include "Point.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Point::Point()
    :   _x(0),
        _y(0)
{
    std::cout
        << "\n"
        << "ℹ️ : Default constructor"
        << std::endl;
}

Point::Point(const float xValue, const float yValue)
    :   _x(xValue),
        _y(yValue)
{
    std::cout
        << "\n"
        << "ℹ️ : Parameterized constructor"
        << std::endl;
}

Point::Point(const Point& object)
    :   _x(object._x),
        _y(object._y)
{
    std::cout
        << "\n"
        << "ℹ️ : Copy constructor"
        << std::endl;
}

Point&  Point::operator=(const Point& object)
{
    std::cout
        << "\n"
        << "ℹ️ : Asignation operator"
        << std::endl;
    if (this != &object)
    {
        // _x and _y are const, cannot be assigned to
        // This operator should not be used; consider removing it
    }
    return (*this);
}

/*-------------------------------DESTRUCTORS-------------------------------*/

Point::~Point()
{
    std::cout
        << "\n"
        << "ℹ️ : Destructor"
        << std::endl;
}

/*-------------------------------GETTERS-------------------------------*/

const Fixed&   Point::getX(void) const
{
    /*std::cout
        << "\n"
        << "ℹ️ : Get x"
        << std::endl;*/
    
    return (_x);
}

const Fixed&   Point::getY(void) const
{
    /*std::cout
        << "\n"
        << "ℹ️ : Get y"
        << std::endl;*/

    return (_y);
}
