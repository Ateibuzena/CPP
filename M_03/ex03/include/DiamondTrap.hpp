#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string         _name;
    
    public:
                            DiamondTrap();
                            DiamondTrap(const std::string& nameValue);
                            DiamondTrap(const DiamondTrap& object);
        DiamondTrap&        operator=(const DiamondTrap& object);

                            ~DiamondTrap();

        const std::string&  getName(void) const;
        void                setName(const std::string& nameValue);

        void                attack(const std::string& target);
        void                whoAmI();
        
        void                printState(void) const;

};

#endif