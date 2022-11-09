#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

# include <iostream>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string const & which_Wronganimal);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal &	operator=(WrongAnimal const& rhs);
		~WrongAnimal(void);

		std::string const&	getType() const;
		void	makeSound() const;

};

#endif