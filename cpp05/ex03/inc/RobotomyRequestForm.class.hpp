#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP
# include "Form.class.hpp"

// class Form;

class RobotomyRequestForm: public Form{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual	~RobotomyRequestForm();
		RobotomyRequestForm &	operator=(RobotomyRequestForm const& rhs);
		virtual int	execute(Bureaucrat const & executor) const;
	private:
		std::string	_target;
};


std::ostream &	operator<<(std::ostream & ostr, RobotomyRequestForm const & var);


#endif