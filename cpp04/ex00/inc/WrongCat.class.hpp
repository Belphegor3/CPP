#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP
# include "WrongAnimal.class.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(WrongCat const& src);
		WrongCat &	operator=(WrongCat const & rhs);
		~WrongCat(void);

		void	makeSound() const;
};

#endif