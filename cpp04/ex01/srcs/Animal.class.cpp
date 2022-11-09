#include "Animal.class.hpp"

Animal::Animal(): type("unknown animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string const & which_animal): type(which_animal)
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal &	Animal::operator=(Animal const& rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.getType();
	}
	return *this;
}

std::string const&	Animal::getType() const{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "unknown sound" << std::endl;
}