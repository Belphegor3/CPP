#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat &	operator=(Bureaucrat const& rhs);
		Bureaucrat &	operator++();
		Bureaucrat &	operator--();
		std::string	getName();
		int			getGrade();
		void		setGrade(int i);
		void		GradeTooHighException();
		void		GradeTooLowException();

	private:
		std::string	const	_name;
		int					_grade;
};

#endif