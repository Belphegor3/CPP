#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP
# include "Form.class.hpp"

// class Form;

class PresidentialPardonForm: public Form{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual	~PresidentialPardonForm();
		PresidentialPardonForm &	operator=(PresidentialPardonForm const& rhs);
		virtual int	execute(Bureaucrat const & executor) const;
	private:
		std::string _target;
};

std::ostream &	operator<<(std::ostream & ostr, PresidentialPardonForm const & var);

#endif