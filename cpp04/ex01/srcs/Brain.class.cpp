#include "Brain.class.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++){
		this->setIdea(i);
	}
}

Brain::Brain(Brain const & src)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++){
		this->setIdea(i);
	}
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &	Brain::operator=(Brain const& rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	for (int i = 0; i < 100; i++){
		_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

void	Brain::setIdea(int i){
	_ideas[i] = "pouet";
}

std::string	Brain::getIdea(int i){
	return (_ideas[i]);
}