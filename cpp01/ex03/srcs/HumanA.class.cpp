#include "HumanA.class.hpp"
// #include "Weapon.class.hpp"

HumanA::HumanA(std::string name, Weapon &weap) : _name(name), _weap(weap)
{
	
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << _weap.getType() << std::endl;
	return ;
}

void	HumanA::setWeapon(Weapon &weap)
{
	_weap = weap;
}