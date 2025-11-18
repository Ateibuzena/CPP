#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include "Print.hpp"

class Span
{
    private:
        unsigned int                    _n;
        std::vector<int>                _data;

    public:
        
                                        Span();
                                        Span(unsigned int n);
                                        Span(const Span &object);
                                        Span &operator=(const Span &object);

                                        ~Span();

        unsigned int                    getN(void) const;
        const std::vector< int >&       getData(void) const;

        void                            addNumber(int number);
        void                            addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int                             shortestSpan(void) const;
        int                             longestSpan(void) const;
};

