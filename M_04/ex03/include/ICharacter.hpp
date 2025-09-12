#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>

class AMateria;

class   ICharacter
{
    private:

    public:

        virtual                     ~ICharacter();

        virtual const std::string&  getName(void) const = 0;

        virtual void                equip(AMateria* m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif