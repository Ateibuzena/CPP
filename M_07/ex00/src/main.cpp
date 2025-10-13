#include "whatever.hpp"
#include <iostream>

// Un tipo personalizado para probar cosas más raras
struct Point
{
    int x;
    int y;

    // Definimos operadores para que funcione con min/max
    bool operator<(const Point &other) const
    {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

    bool operator>(const Point &other) const
    {
        if (x == other.x)
            return y > other.y;
        return x > other.x;
    }
};

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return (os);
}

int main(void)
{
    std::cout << "===== INT TESTS =====" << std::endl;
    int a = 2;
    int b = 3;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "\n===== NEGATIVE & EQUAL INT TESTS =====" << std::endl;
    int x = -5;
    int y = -5;
    std::cout << "Data: x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << " (should be second: -5)" << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << " (should be second: -5)" << std::endl;

    int m = -42;
    int n = 0;
    std::cout << "Data: m = " << m << ", n = " << n << std::endl;
    std::cout << "min(m, n) = " << ::min(m, n) << std::endl;
    std::cout << "max(m, n) = " << ::max(m, n) << std::endl;

    std::cout << "\n===== FLOAT TESTS =====" << std::endl;
    float f1 = 42.42f;
    float f2 = 42.43f;
    std::cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
    ::swap(f1, f2);
    std::cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;

    std::cout << "\n===== DOUBLE TESTS =====" << std::endl;
    double d1 = -0.000001;
    double d2 = 0.000001;
    std::cout << "Data: d1 = " << d1 << ", d2 = " << d2 << std::endl;
    std::cout << "min(d1, d2) = " << ::min(d1, d2) << std::endl;
    std::cout << "max(d1, d2) = " << ::max(d1, d2) << std::endl;

    std::cout << "\n===== STRING TESTS =====" << std::endl;
    std::string c = "Hellwi";
    std::string d = "World";
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    std::cout << "\n===== STRING CASE SENSITIVITY TESTS =====" << std::endl;
    std::string s1 = "apple";
    std::string s2 = "Apple";
    std::cout << "Data: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min(s1, s2) = " << ::min(s1, s2) << " (remember: 'A' < 'a')" << std::endl;
    std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;

    std::cout << "\n===== CHAR TESTS =====" << std::endl;
    char c1 = 'A';
    char c2 = 'a';
    std::cout << "Data: c1 = " << c1 << ", c2 = " << c2 << std::endl;
    std::cout << "min(c1, c2) = " << ::min(c1, c2) << " (A=65, a=97)" << std::endl;
    std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;

    std::cout << "\n===== CUSTOM TYPE TESTS =====" << std::endl;
    Point p1 = {1, 5};
    Point p2 = {2, 3};
    std::cout << "p1 = " << p1 << ", p2 = " << p2 << std::endl;
    std::cout << "min(p1, p2) = " << ::min(p1, p2) << std::endl;
    std::cout << "max(p1, p2) = " << ::max(p1, p2) << std::endl;
    ::swap(p1, p2);
    std::cout << "After swap: p1 = " << p1 << ", p2 = " << p2 << std::endl;

    std::cout << "\n===== EDGE TESTS =====" << std::endl;
    std::cout << "min(0, 0) = " << ::min(0, 0) << " (should return second 0)" << std::endl;
    std::cout << "max(0, 0) = " << ::max(0, 0) << " (should return second 0)" << std::endl;

    std::cout << "\n===== CONST TESTS =====" << std::endl;
    const int ca = 10;
    const int cb = 20;
    std::cout << "Data: ca = " << ca << ", cb = " << cb << std::endl;
    std::cout << "min(ca, cb) = " << ::min(ca, cb) << std::endl;
    std::cout << "max(ca, cb) = " << ::max(ca, cb) << std::endl;

    return (0);
}
