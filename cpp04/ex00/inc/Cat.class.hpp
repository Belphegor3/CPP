#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP
# include "Animal.class.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(Cat const& src);
		Cat &	operator=(Cat const & rhs);
		~Cat(void);

		void	makeSound() const;
};

#endif