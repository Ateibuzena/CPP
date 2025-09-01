#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class   ClapTrap
{
    private:
        std::string         _name;
        unsigned int        _hit;
        unsigned int        _energy;
        unsigned int        _damage;
        bool                _game;
    
    public:
                            ClapTrap();
                            ClapTrap(const std::string& nameValue);
                            ClapTrap(const ClapTrap& object);
        ClapTrap&           operator=(const ClapTrap& object);

        virtual             ~ClapTrap();

        const std::string&  getName(void) const;
        const unsigned int& getHit(void) const;
        const unsigned int& getEnergy(void) const;
        const unsigned int& getDamage(void) const;
        bool                getGame(void) const;

        void                setName(const std::string& nameValue);
        void                setHit(const int hitValue);
        void                setEnergy(const int energyValue);
        void                setDamage(const int damageValue);
        void                setGame(const bool gameValue);

        virtual void        attack(const std::string& target);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);

        void                printState(void) const;
};

#endif