#include <iostream>

class HumanB
{
	private:
		std::string	_name;
		Weapon		_dmg;
	public:
		HumanB(std::string name);
		~HumanB();
		
		void	attack(void);
		void	setWeapon(Weapon weap);
};

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
	std::cout << this->_name << " attacks with their " << _dmg.getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weap)
{
	weap = _dmg;
}
