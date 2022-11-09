#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>
# include "Brain.class.hpp"

class AAnimal{
	protected:
		std::string type;
	public:
		std::string const&	getType() const;
		virtual void	makeSound() const = 0;
		virtual ~AAnimal();
};

#endif