#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/*Fixed.cpp*/
class   Fixed
{
    private:
        int                 _rawBits;
        int                 _copy;
        static const int    _bits = 8;

    public:
                            Fixed(); //default constructor
                            Fixed(const int integer); //parameterized constructor
                            Fixed(const float floatingPoint); //parameterized constructor
                            Fixed(const Fixed& object); //copy constructor
                            ~Fixed(); //destructor
                
        Fixed&              operator=(const Fixed& object); //asignation operator
        void                setRawBits(const int rawBitsValue);
        int                 getRawBits(void) const;

        int                 toInt(void) const;
        float               toFloat(void) const;
};


/*utils.cpp*/
std::ostream                &operator<<(std::ostream& fd, const Fixed& object); //overload operator update ostream

#endif