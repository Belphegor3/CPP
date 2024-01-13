#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <iostream>
#include "Weapon.class.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weap;
	public:
		HumanA(std::string name, Weapon &weap);
		~HumanA();
		
		void	attack(void);
		void	setWeapon(Weapon &weap);
};

#endif