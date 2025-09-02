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

};

#endif