#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# include <iostream>
# define MAX_HP 10
# define MAX_PM 10
# define ATK 0

class ClapTrap
{
	private:
		unsigned int	_hp;
		unsigned int	_atk;
		unsigned int	_pm;
		std::string		_name;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& src);
		ClapTrap &	operator=(ClapTrap & rhs);
		~ClapTrap(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int	getHp(void);
		int	getPm(void);
		int	getAtk(void);
		std::string	getName(void);
};

#endif