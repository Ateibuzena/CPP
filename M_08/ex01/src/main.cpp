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
    std::vector< int >    vec;

    vec = sp.getData();
    printVector(vec, "My sp from Span ");

    // Attempt to add a number beyond the capacity of the Span
    try
    {
        sp.addNumber(12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    vec = sp.getData();
    printVector(vec, "My sp from Span ");

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
    vec = sp2.getData();
    printVector(vec, "My sp2 from Span ");

    // Test shortestSpan with only one number
    Span sp3 = Span(1);
    try
    {
        sp3.addNumber(42);
        sp3.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    vec = sp3.getData();
    printVector(vec, "My sp3 from Span ");

    // Test adding a range of numbers
    Span sp4 = Span(20);
    try
    {
        std::vector<int> numbers;
        for (int i = 0; i < 10; i++)
        {
            numbers.push_back(i * 10);
            sp4.addNumber(i);
        }
        printVector(numbers, "Numbers to add");

        sp4.addNumber(numbers.begin(), numbers.end());
        printVector(sp4.getData(), "My sp4 from Span after adding range");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}