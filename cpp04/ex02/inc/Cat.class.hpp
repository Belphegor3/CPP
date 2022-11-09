#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP
# include "Animal.class.hpp"
# include "Brain.class.hpp"

class Cat: public AAnimal{
	public:
		Cat();
		Cat(Cat const& src);
		Cat &	operator=(Cat const & rhs);
		~Cat(void);

		virtual void	makeSound() const;
	private:
		Brain*	_brain;
};

#endif