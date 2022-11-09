#include "Cat.class.hpp"
#include "Brain.class.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(Cat const& src): Animal(src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = src;
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _brain;
}

Cat &	Cat::operator=(Cat const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou Miaou" << std::endl;
}