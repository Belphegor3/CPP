#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP
# include "Bureaucrat.class.hpp"
# include <iostream>

// class Bureaucrat;

class Form{
	public:
		Form(std::string target, int s_grade, int e_grade);
		Form(Form const & rhs);
		Form &	operator=(Form const& rhs);
		virtual	~Form();
		std::string		getName() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		bool			getSigned() const;
		void			setSigned(bool sign);
		void			setSignGrade(int i);
		void			setExecuteGrade(int i);
		void			beSigned(Bureaucrat const& random);
		virtual	int	execute(Bureaucrat const & executor) const;

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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("not signed yet");
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