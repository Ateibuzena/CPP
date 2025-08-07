#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class   HumanA
{
    private:
        std::string         _myName;
        Weapon&             _myWeapon; //always has a weapon and cant change it
    
    public:
                            HumanA(const std::string& nameValue, Weapon& weaponValue);
                            ~HumanA();

        void                attack(void) const;
        void                setName(const std::string& nameValue);
        const std::string&  getName(void) const;
        const Weapon&       getWeapon(void) const;

};

#endif