#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class   Fixed
{
    private:
        int                 _rawBits;
        int                 _copy;
        static const int    _bits = 8;

    public:
                            Fixed(); //default constructor
                            Fixed(const Fixed& object); //copy constructor
                            ~Fixed(); //destructor
                
        Fixed&              operator=(const Fixed& object); //asignation operator

        void                setRawBits(const int rawBitsValue);
        int                 getRawBits(void) const;
};

#endif