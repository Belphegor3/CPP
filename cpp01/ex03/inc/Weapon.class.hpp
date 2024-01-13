#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon();
	Weapon(std::string n);

	~Weapon();
	std::string const&	getType();
	void	setType(std::string new_type);
};

#endif
