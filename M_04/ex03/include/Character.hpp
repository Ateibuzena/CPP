#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class   Character: public ICharacter
{
    private:
        std::string                 _name;
        AMateria*                   _inventary[4];
        int                         _position[2];

    public:
                                    Character();
                                    Character(const std::string& nameValue);
                                    Character(const Character& object);
        Character&                  operator=(const Character& object);

                                    ~Character();

        const std::string&          getName(void) const;
        AMateria*                   getMateria(int idx) const;
        const int*                  getPosition(void) const;

        void                        setName(const std::string& nameValue);
        void                        setMateria(int idx, AMateria* materia);
        void                        setPosition(int x, int y);

        void                        showInventary(void) const;
        void                        showCharacter(void) const;

        void                        equip(AMateria* m);
        void                        unequip(int idx);
        void                        use(int idx, ICharacter& target);

        void                        move(char input);
};

#endif