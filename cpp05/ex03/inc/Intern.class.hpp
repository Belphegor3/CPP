#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <iostream>
// # include "Form.class.hpp"
# include "RobotomyRequestForm.class.hpp"
# include "PresidentialPardonForm.class.hpp"
# include "ShrubberyCreationForm.class.hpp"

class Intern{
	public:
		Intern();
		Intern(Intern const & src);
		Intern &	operator=(Intern const& rhs);
		~Intern();
		Form*	makeForm(std::string name, std::string target);
		class FormDoesntExist : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("This form type doesn't exist");
				}
		};
};

#endif