#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP
# include "Animal.class.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(Dog const & src);
		Dog &	operator=(Dog const & rhs);
		~Dog(void);

		void	makeSound() const;
};

#endif