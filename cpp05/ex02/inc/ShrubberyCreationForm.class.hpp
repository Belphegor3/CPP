#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP
# include "Bureaucrat.class.hpp"
# include <iostream>

class Bureaucrat;

class ShrubberyCreationForm{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(std::string name, std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const& rhs);
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


std::ostream &	operator<<(std::ostream & ostr, ShrubberyCreationForm const & var);


#endif