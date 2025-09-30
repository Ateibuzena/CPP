#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

typedef Base* (*BaseConstructor)(void);

Base*   generate(void)
{
    srand(time(0)); //seed
    int index = rand() % 3;

    if (index == 0)
        return (new A());
    if (index == 1)
        return (new B());
    return (new C());
}

void    identify(Base* p)
{
    A* a =  dynamic_cast<A*>(p);
    B* b =  dynamic_cast<B*>(p);
    C* c =  dynamic_cast<C*>(p);

    if (a)
    {
        std::cout
                << "Pointer a"
                << std::endl;
    }
    else if (b)
    {
        std::cout
                << "Pointer b"
                << std::endl;
    }
    else if (c)
    {
        std::cout
                << "Pointer c"
                << std::endl;
    }
    else
    {
        std::cout
            << "I don't know what I am"
            << std::endl;
    }
}

void    identify(Base& p)
{
    try 
    {
        A& a =  dynamic_cast<A&>(p); //with references throw a exception
        std::cout
                << "Reference A"
                << std::endl;
        (void)a;
    }
    catch (std::exception& error)
    {
        std::cout
                << "I don't know what I am but A not\n"
                << "exception message from exception class: "
                << error.what()
                << std::endl;
    }
    try
    {
        B& b =  dynamic_cast<B&>(p);
        std::cout
                << "Reference B"
                << std::endl;
        (void)b;
    }
    catch (std::exception& error)
    {
        std::cout
                << "I don't know what I am but B not\n"
                << "exception message from exception class: "
                << error.what()
                << std::endl;
    }
    try
    {
        C& c =  dynamic_cast<C&>(p);
        std::cout
                << "Reference C"
                << std::endl;
        (void)c;
    }
    catch (std::exception& error)
    {
        std::cout
                << "I don't know what I am but C not\n"
                << "exception message from exception class: "
                << error.what()
                << std::endl;
    }
}