#include "WrongCat.class.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& src): WrongAnimal(src)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaou Miaou" << std::endl;
}