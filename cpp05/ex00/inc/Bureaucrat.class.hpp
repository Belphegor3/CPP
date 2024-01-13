#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>

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

	private:
		std::string	const	_name;
		int					_grade;
};

std::ostream &	operator<<(std::ostream & ostr, Bureaucrat const & var);

#endif