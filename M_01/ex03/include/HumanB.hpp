#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class   HumanB
{
    private:
        std::string         _myName;
        Weapon*             _myWeapon;
    
    public:
                            HumanB();
                            HumanB(const std::string& nameValue);
                            HumanB(const std::string& nameValue, Weapon& weaponValue);
                            ~HumanB();

        void                attack(void) const;
        void                setName(const std::string& nameValue);
        void                setWeapon(Weapon& weaponValue);
        void                unsetWeapon(void);
        const std::string&  getName(void) const;
        const Weapon*       getWeapon(void) const; //return pointer because may haven't a weapon

};

#endif