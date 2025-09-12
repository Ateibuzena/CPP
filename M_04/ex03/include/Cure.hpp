#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class   Cure: public AMateria
{
    private:
    
    public:
                            Cure();
                            Cure(const std::string& typeValue);
                            Cure(const Cure& object);
        Cure&               operator=(const Cure& object);

        virtual             ~Cure();

        AMateria*           clone() const; //pure virtual from AMateria
        void                use(ICharacter& target) const;
};

#endif