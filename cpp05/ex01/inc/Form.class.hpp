#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP
# include "Bureaucrat.class.hpp"
# include <iostream>

class Bureaucrat;

class Form{
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int sign_grade, int execute_grade);
		Form(Form const & src);
		~Form();
		Form &	operator=(Form const& rhs);
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		bool		getSigned() const;
		void		setSigned(bool sign);
		void		setSignGrade(int i);
		void		setExecuteGrade(int i);
		void		beSigned(Bureaucrat const& random);
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
		std::string const	_name;
		int const			_sign_grade;
		int const			_execute_grade;
		bool				_signed;
};


std::ostream &	operator<<(std::ostream & ostr, Form const & var);


#endif