#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP


#include <iostream>
#include "Weapon.class.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_dmg;
	public:
		HumanB(std::string name);
		~HumanB();
		
		void	attack(void);
		void	setWeapon(Weapon &weap);
};

#endif