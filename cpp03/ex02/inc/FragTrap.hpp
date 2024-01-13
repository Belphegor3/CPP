#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>
# define MAX_HP 100
# define MAX_PM 100
# define ATK 30

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap& src);
		FragTrap &	operator=(FragTrap & cpy);
		~FragTrap(void);
		void	attack(const std::string& target);
		void	highFivesGuys();
};

#endif