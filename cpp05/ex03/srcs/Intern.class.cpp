#include "Intern.class.hpp"
#include <stdlib.h>

Intern::Intern(){
}

Intern::Intern(Intern const & src){
	*this = src;
}

Intern::~Intern(){
}

Intern &	Intern::operator=(Intern const& rhs)
{
	(void)rhs;
	return *this;
}

std::string form_types[3] = { "robotomy request", "presidential pardon", "shrubbery creation" };

Form*	Intern::makeForm(std::string name, std::string target){
	int i = 0;
	while (i < 3){
		if (name == form_types[i])
			break ;
		i++;
	}
	switch(i){
		case (0):
			// Form* a = new RobotomyRequestForm(target);
			// atexit(delete a);
			std::cout << "Intern creates " << form_types[i] << std::endl;
			return (new RobotomyRequestForm(target));
			break ;
		case (1):
			// Form* b = new PresidentialPardonForm(target);
			// atexit(delete b);
			std::cout << "Intern creates " << form_types[i] << std::endl;
			return (new PresidentialPardonForm(target));
			break ;
		case (2):
			// Form* c = new ShrubberyCreationForm(target);
			// atexit(delete c);
			std::cout << "Intern creates " << form_types[i] << std::endl;
			return (new ShrubberyCreationForm(target));
			break ;
		default:
			std::cerr << "Intern can't create " << name << std::endl;
			throw(FormDoesntExist());
	}
	Form* d = new Form(target, 1, 1);
	return d;
}
