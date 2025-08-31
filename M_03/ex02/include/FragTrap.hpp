#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class   FragTrap: public ClapTrap
{
    private:
        bool        _gateKeeper;
    
    public:
                    FragTrap();
                    FragTrap(const std::string& nameValue);
                    FragTrap(const FragTrap& object);
        FragTrap&   operator=(const FragTrap& object);

                    ~FragTrap();

        void        attack(const std::string& target);
        void        guardGate(void);
        void        highFivesGuys(void);

        void        printState(void) const;
};

#endif