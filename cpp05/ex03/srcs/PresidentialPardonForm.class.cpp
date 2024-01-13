#include "PresidentialPardonForm.class.hpp"
// #include "Bureaucrat.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form(target, 145, 137), _target(target){
	;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): Form(src), _target(src._target){
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return *this;
}

std::ostream &	operator<<(std::ostream & ostr, PresidentialPardonForm const & var)
{
	ostr << "PresidentialPardonForm target: " << var.getName() << ", signature grade = " << var.getSignGrade() << ", execution grade = " << var.getExecuteGrade();
	return (ostr);
}

int	PresidentialPardonForm::execute(Bureaucrat const& executor) const{
	try{
		if (this->getSigned() == false)
			throw std::exception();
	}
	catch(std::exception& e){
		std::cout << this->getName() << " not signed yet" << std::endl;
		return 1;
	}
	try{
		if (executor.geteGrade() > this->getExecuteGrade())
			throw std::exception();
	}
	catch(std::exception& e){
		std::cout << executor.getName() << " execute grade too low" << std::endl;
		return 1;
	}
	/*		useless pardon presidentiel		*/
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return 0;
}