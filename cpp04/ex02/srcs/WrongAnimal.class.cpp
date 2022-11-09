#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal(): type("unknown Wronganimal")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const & which_Wronganimal): type(which_Wronganimal)
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const& rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.getType();
	}
	return *this;
}

std::string const&	WrongAnimal::getType() const{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "unknown sound" << std::endl;
}