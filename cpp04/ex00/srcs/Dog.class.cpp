#include "Dog.class.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const & src): Animal(src)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &	Dog::operator=(Dog const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf Wouf" << std::endl;
}