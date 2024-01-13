#include "HumanB.class.hpp"
// #include "Weapon.class.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << _dmg->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weap)
{
	_dmg = &weap;
}