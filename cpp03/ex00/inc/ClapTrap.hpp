#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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

ClapTrap::ClapTrap()
{
	_name = "ClapFault";
	_pm = MAX_PM;
	_hp = MAX_HP;
	_atk = ATK;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_pm = MAX_PM;
	_hp = MAX_HP;
	_atk = ATK;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_pm > 0){
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _atk << " points of damage!" << std::endl;
		_pm--;
	}
	else
		std::cout << "ClapTrap " << _name << " ran out of mana !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_pm == 0)
		std::cout << "Nothing happens" << std::endl;
	else if (amount > _hp){
		if (_hp != 0)
			std::cout << _name << " died......" << std::endl;
		else
			std::cout << _name << " is already dead ! Bruh...." << std::endl;
		_hp = 0;
	}
	else{
		std::cout << _name << " took " << amount << " damages" << std::endl;
		_hp = _hp - amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp + amount < MAX_HP){
		_hp = _hp + amount;
		std::cout << _name << " has been healed by " << amount << std::endl;
	}
	else{
		std::cout << _name << " has been healed by " << MAX_HP - _hp << " recovering 100% hp" << std::endl;
		_hp = MAX_HP;
	}
}

int	ClapTrap::getAtk(void)
{
	return (_atk);
}

int	ClapTrap::getPm(void)
{
	return (_pm);
}

int	ClapTrap::getHp(void)
{
	return (_hp);
}

std::string	ClapTrap::getName(void)
{
	return (_name);
}

ClapTrap &	ClapTrap::operator=(ClapTrap & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		_hp = rhs.getHp();
		_atk = rhs.getAtk();
		_pm = rhs.getPm();
		_name = rhs.getName();
	}
	return *this;
}

#endif