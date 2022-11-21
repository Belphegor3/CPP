#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
# include "Form.class.hpp"
class Form;

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat::Bureaucrat(std::string name, int sgrade, int egrade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat &	operator=(Bureaucrat const& rhs);
		Bureaucrat &	operator++();
		Bureaucrat &	operator--();
		std::string	getName() const;
		int			geteGrade() const;
		int			getsGrade() const;
		void		seteGrade(int i);
		void		setsGrade(int i);
		void		GradeTooHighException();
		void		GradeTooLowException();
		void		signForm(Form const & form);
		void		executeForm(Form const & form);

	private:
		std::string	const	_name;
		int					_egrade;
		int					_sgrade;
};

#endif