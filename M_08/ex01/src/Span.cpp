#include "Span.hpp"

Span::Span()
    :   _n(0),
        _data()
{

}

Span::Span(unsigned int n)
    :   _n(n),
        _data()
{

}

Span::Span(const Span &object)
    :   _n(object._n),
        _data(object._data)
{
    
}

Span& Span::operator=(const Span &object)
{

    if (this != &object)
    {
        _n = object._n;
        _data = object._data;
    }
    
    return (*this);
}

Span::~Span()
{

}

unsigned int    Span::getN(void) const
{
    return (_n);
}

const std::vector< int >&       Span::getData(void) const
{
    return (_data);
}

void    Span::addNumber(int number)
{
    if (_data.size() >= _n)
        throw std::out_of_range("Span is full");

    _data.push_back(number);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _data.size() > _n)
        throw std::out_of_range("Span is full");
    
    _data.insert(_data.end(), begin, end);
}

int Span::shortestSpan(void) const
{
    if (_data.size() < 2)
        throw (std::length_error("Not enough numbers to find a span"));
    
    std::vector< int > sorted = _data; 
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = sorted[1] - sorted[0];

    unsigned int i = 0;
    while (i < sorted.size())
    {
        unsigned int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
        i++;
    }
    return (minSpan);
}

int Span::longestSpan(void) const
{
    if (_data.size() < 2)
        throw (std::length_error("Not enough numbers to find a span"));
    
    std::vector< int > sorted = _data; 
    std::sort(sorted.begin(), sorted.end());

    unsigned int maxSpan = sorted[sorted.size() - 1] - sorted[0];

    return (maxSpan);
}
