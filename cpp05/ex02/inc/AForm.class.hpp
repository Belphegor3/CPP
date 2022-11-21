#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP
# include "Bureaucrat.class.hpp"
# include <iostream>

class Bureaucrat;

class AForm{
	public:
		virtual	~AForm();
		std::string		getName() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		bool			getSigned() const;
		void			setSigned(bool sign);
		void			setSignGrade(int i);
		void			setExecuteGrade(int i);
		virtual void	beSigned(Bureaucrat const& random) = 0;
		void			GradeTooHighException();
		void			GradeTooLowException();

	private:
		std::string const	_name;
		int const			_sign_grade;
		int const			_execute_grade;
		bool				_signed;
		std::string const	_target;
};


std::ostream &	operator<<(std::ostream & ostr, AForm const & var);


#endif