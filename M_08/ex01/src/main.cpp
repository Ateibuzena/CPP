#include "Span.hpp"

int main(void)
{
    // Example usage of the Span class
    Span sp = Span(5);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Attempt to add a number beyond the capacity of the Span
    try
    {
        sp.addNumber(12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test shortestSpan and longestSpan with empty Span
    Span sp2 = Span();
    try
    {
        sp2.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test shortestSpan with only one number
    Span sp3 = Span(1);
    try
    {
        sp3.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    return (0);
}