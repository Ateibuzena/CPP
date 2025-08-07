#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class   Weapon
{
    private:
        std::string         _type;
    
    public:
                            Weapon();
                            Weapon(const std::string& typeValue);
                            ~Weapon();

        void                setType(const std::string& typeValue);
        const std::string&  getType(void) const;
};

#endif
