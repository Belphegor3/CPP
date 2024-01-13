#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>
# define MAX_HP 100
# define MAX_PM 50
# define ATK 20

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap& src);
		ScavTrap &	operator=(ScavTrap & cpy);
		~ScavTrap(void);
		void	attack(const std::string& target);
		void	guardGate();
};

#endif