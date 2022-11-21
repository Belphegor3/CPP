#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP
# include "Bureaucrat.class.hpp"
# include <iostream>

class Bureaucrat;

class PresidentialPardonForm{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(std::string name, std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm();
		PresidentialPardonForm &	operator=(PresidentialPardonForm const& rhs);
		std::string		getName() const;
		int				getSignGrade();
		int				getExecuteGrade();
		int	beExecuted(Bureaucrat const & executor)
		

	private:
		std::string const	_name;
		int const			_sign_grade;
		int const			_execute_grade;
		std::string const	_target;
};


std::ostream &	operator<<(std::ostream & ostr, PresidentialPardonForm const & var);


#endif