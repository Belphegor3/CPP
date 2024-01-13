#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
# include "Form.class.hpp"
class Form;

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(int grade, std::string name);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat &	operator=(Bureaucrat const& rhs);
		Bureaucrat &	operator++();
		Bureaucrat &	operator--();
		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int i);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low");
				}
		};
		void		signForm(Form const & form);

	private:
		std::string	const	_name;
		int					_grade;
};

#endif