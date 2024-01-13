#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap::ClapTrap()
{
	_name = "FragFault";
	_pm = MAX_PM;
	_hp = MAX_HP;
	_atk = ATK;
	std::cout << "Default FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap::ClapTrap(name)
{
	_name = name;
	_pm = MAX_PM;
	_hp = MAX_HP;
	_atk = ATK;
	std::cout << "Default FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap & src): ClapTrap::ClapTrap(src)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor FragTrap " << _name << " called" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap & cpy)
{
	std::cout << "Copy FragTrap assignement operator called" << std::endl;
	_name = cpy._name;
	_hp = cpy._hp;
	_pm = cpy._pm;
	_atk = cpy._atk;
	return *this;
}

void	FragTrap::attack(const std::string& target)
{
	if (_pm > 4){
		std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _atk << " points of damage!" << std::endl;
		_pm -= 5;
	}
	else
		std::cout << "FragTrap " << _name << " ran out of mana..." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << _name << " asked for a high five !" << std::endl;
}