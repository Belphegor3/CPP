#include "Animal.class.hpp"


AAnimal::~AAnimal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string const&	AAnimal::getType() const{
	return (type);
}