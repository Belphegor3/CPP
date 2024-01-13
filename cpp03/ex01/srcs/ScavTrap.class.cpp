#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap::ClapTrap()
{
	_name = "ScavFault";
	_pm = MAX_PM;
	_hp = MAX_HP;
	_atk = ATK;
	std::cout << "Default ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap::ClapTrap(name)
{
	_name = name;
	_pm = MAX_PM;
	_hp = MAX_HP;
	_atk = ATK;
	std::cout << "Default ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap & src): ClapTrap::ClapTrap(src)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap & cpy)
{
	std::cout << "Copy ScavTrap assignement operator called" << std::endl;
	_name = cpy._name;
	_hp = cpy._hp;
	_pm = cpy._pm;
	_atk = cpy._atk;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_pm > 4){
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _atk << " points of damage!" << std::endl;
		_pm -= 5;
	}
	else
		std::cout << "ScavTrap " << _name << " ran out of mana..." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << _name << " entered Gate keeper mode !" << std::endl;
}