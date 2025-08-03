#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class   Zombie
{
    private:
        std::string _name;
    
    public:
                            Zombie();
                            ~Zombie();
                            Zombie(const std::string& nameValue);

        void                announce(void) const;
        void                setName(const std::string& name);
        const std::string&  getName(void) const;
};

Zombie* zombieHorde(const int N, const std::string nameValue);
void    deleteHorde(const int N, Zombie* zombieHorde);

#endif