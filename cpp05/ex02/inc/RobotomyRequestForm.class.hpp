#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP
# include "Bureaucrat.class.hpp"
# include <iostream>

class Bureaucrat;

class RobotomyRequestForm{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual 	~RobotomyRequestForm();
		RobotomyRequestForm &	operator=(RobotomyRequestForm const& rhs);
		std::string		getName() const;
		int				getSignGrade();
		int				getExecuteGrade();
		virtual int	execute(Bureaucrat const & executor)
		

	private:
		std::string const	_name;
		int const			_sign_grade;
		int const			_execute_grade;
		std::string const	_target;
};


std::ostream &	operator<<(std::ostream & ostr, RobotomyRequestForm const & var);


#endif