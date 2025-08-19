#include "Fixed.hpp"
#include "Point.hpp"

std::ostream    &operator<<(std::ostream& fd, const Fixed& object)
{
    std::cout
        << "\nℹ️  Extern: Operator overload"
        << std::endl;
    
    fd << object.toFloat();
    
    return (fd);
}

Fixed areaTriangle(const Point& p1, const Point& p2, const Point& p3)
{
    Fixed   area = (p1.getX() * (p2.getY() - p3.getY())
                    + p2.getX() * (p3.getY() - p1.getY())
                    + p3.getX() * (p1.getY() - p2.getY())) / Fixed(2.0f);

    if (area < Fixed(0))
        area = area * Fixed(-1);
    return (area);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    const Fixed   A = areaTriangle(a, b, c);
    const Fixed   A1 = areaTriangle(point, b, c);
    const Fixed   A2 = areaTriangle(a, point, c);
    const Fixed   A3 = areaTriangle(a, b, point);

    if (A == A1 + A2 + A3 && A1 > Fixed(0) && A2 > Fixed(0) && A3 > Fixed(0))
        return (true);
    return (false);
}
