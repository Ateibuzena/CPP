#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

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

        void                            addNumber(int number);

        int                             shortestSpan(void) const;
        int                             longestSpan(void) const;
};

