#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP
# include "Form.class.hpp"

// class Form;

class ShrubberyCreationForm: public Form{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual	~ShrubberyCreationForm();
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const& rhs);
		virtual int	execute(Bureaucrat const & executor) const;
	private:
		std::string _target;
};

std::ostream &	operator<<(std::ostream & ostr, ShrubberyCreationForm const & var);

#endif