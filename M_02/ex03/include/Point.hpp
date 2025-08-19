#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/*Point.cpp*/
class   Point
{
    private:
        const Fixed     _x;
        const Fixed     _y;
        Point&          operator=(const Point& object); //asignation operator not useful

    public:
                        Point(); //default constructor
                        Point(const float xValue, const float yValue); //parameterized constructor
                        Point(const Point& object); //copy constructor
                        ~Point(); //destructor

        const Fixed&    getX(void) const;
        const Fixed&    getY(void) const;
};

/*utils.cpp*/
bool                    bsp(Point const a, Point const b, Point const c, Point const point);
Fixed                   areaTriangle(const Point& p1, const Point& p2, const Point& p3);

#endif