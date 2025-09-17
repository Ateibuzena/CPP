#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Ana", 0); // hight exception
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    try
    {
        Bureaucrat b("Luis", 151); // low exception
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    try
    {
        Bureaucrat c("Mario", 2);
        std::cout << c << std::endl;
        c.incrementGrade(); // 1
        std::cout << c << std::endl;
        c.incrementGrade(); // high exception
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    return (0);
}
