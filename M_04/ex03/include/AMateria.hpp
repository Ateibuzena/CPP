#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class   AMateria
{
    protected:
        std::string         _type;
    
    public:
                            AMateria();
                            AMateria(const std::string& typeValue);
                            AMateria(const AMateria& object);
        AMateria&           operator=(const AMateria& object);

        virtual             ~AMateria();

        const std::string&  getType(void) const;
        
        void                setType(const std::string& typeValue);

        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target) const;
};

#endif