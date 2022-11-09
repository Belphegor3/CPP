#include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon		_weap;
	public:
		HumanA(std::string name, Weapon weap);
		~HumanA();
		
		void	attack(void);
		void	setWeapon(Weapon weap);
};

HumanA::HumanA(std::string name, Weapon weap) : _name(name), _weap(weap)
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

void	HumanA::setWeapon(Weapon weap)
{
	weap = _weap;
}