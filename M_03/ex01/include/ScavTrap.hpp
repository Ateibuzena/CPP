#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class   ScavTrap: public ClapTrap
{
    private:
        bool        _gateKeeper;
    
    public:
                    ScavTrap();
                    ScavTrap(const std::string& nameValue);
                    ScavTrap(const ScavTrap& object);
        ScavTrap&   operator=(const ScavTrap& object);

                    ~ScavTrap();

        bool        getGateKeeper(void) const;
                    
        void        setGateKeeper(bool gateKeeperValue);

        void        attack(const std::string& target);
        void        guardGate(void);

        void        printState(void) const;
};

#endif