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

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string n) :_type(n) 
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
	return ;
}
