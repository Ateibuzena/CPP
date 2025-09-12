#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class   Ice: public AMateria
{
    private:
    
    public:
                            Ice();
                            Ice(const std::string& typeValue);
                            Ice(const Ice& object);
        Ice&                operator=(const Ice& object);

        virtual             ~Ice();

        AMateria*           clone() const; //pure virtual from AMateria
        void                use(ICharacter& target) const;
};

#endif