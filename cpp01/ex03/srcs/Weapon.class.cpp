#include "Weapon.class.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string n) : _type(n) 
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string	const&	Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}