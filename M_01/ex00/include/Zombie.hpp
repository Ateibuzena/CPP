#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
							Zombie();
							~Zombie();
							Zombie(const std::string& nameValue);

		void				announce(void) const;
		void				setName(const std::string& nameValue);
		const std::string&	getName() const;
};

Zombie* newZombie(const std::string& nameValue);
void    randomChump(const std::string  nameValue);

#endif