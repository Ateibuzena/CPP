#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cmath>

class   Vector
{
    public:
        double  _x;
        double  _y;
        double  _z;

                Vector(double x, double y, double z);
        
        Vector  operator+(const Vector& object) const;
        Vector  operator-(const Vector& object) const;
        // Scalar product
        Vector  operator*(double k) const;
        // Dot product
        double  dot(const Vector& object) const;

        bool    operator==(const Vector& object) const;
        bool    operator!=(const Vector& object) const;

        double  magnitude() const;
        bool    operator<(const Vector& object) const;
        bool    operator>(const Vector& object) const;

};

std::ostream&   operator<<(std::ostream& fd, const Vector& object);

#endif