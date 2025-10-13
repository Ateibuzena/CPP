#include "Vector.hpp"

Vector::Vector(double x=0, double y=0, double z=0)
    :   _x(x),
        _y(y),
        _z(z)
{

}
        
Vector  Vector::operator+(const Vector& object) const
{
    double new_x = _x + object._x;
    double new_y = _y + object._y;
    double new_z = _z + object._z;

    Vector result = Vector(new_x, new_y, new_z);
    return (result);
}

Vector  Vector::operator-(const Vector& object) const
{
    double new_x = _x - object._x;
    double new_y = _y - object._y;
    double new_z = _z - object._z;

    Vector result = Vector(new_x, new_y, new_z);
    return (result);
}

// Scalar product
Vector  Vector::operator*(double k) const
{
    double new_x = _x * k;
    double new_y = _y * k;
    double new_z = _z * k;

    Vector result = Vector(new_x, new_y, new_z);
    return (result);
}

// Dot product
double  Vector::dot(const Vector& object) const
{
    double new_x = _x * object._x;
    double new_y = _y * object._y;
    double new_z = _z * object._z;

    double result = new_x + new_y + new_z;
    return (result);
}

bool    Vector::operator==(const Vector& object) const
{
    const double eps = 1e-9;
    if (std::abs(_x - object._x) < eps &&
            std::abs(_y - object._y) < eps &&
            std::abs(_z - object._z) < eps)
        return (true);
    return (false);
}

bool    Vector::operator!=(const Vector& object) const
{
    if (*this == object)
        return (true);
    return (false);
}


double  Vector::magnitude() const
{
    double result = std::sqrt(_x*_x + _y*_y + _z*_z);
    return (result);
}

bool    Vector::operator<(const Vector& object) const
{
    if (this->magnitude() < object.magnitude())
        return (true);
    return (false);
}

bool    Vector::operator>(const Vector& object) const
{
    if (this->magnitude() > object.magnitude())
        return (true);
    return (false);
}

std::ostream&   operator<<(std::ostream& fd, const Vector& object)
{
    fd << "( " << object._x << ", " << object._y << ", " << object._z << " )";
    return (fd);
}