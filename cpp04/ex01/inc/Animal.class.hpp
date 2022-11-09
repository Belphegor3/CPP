#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>
# include "Brain.class.hpp"

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string const & which_animal);
		Animal(Animal const & src);
		Animal &	operator=(Animal const& rhs);
		virtual ~Animal(void);

		std::string const&	getType() const;
		virtual void	makeSound() const;
};

#endif