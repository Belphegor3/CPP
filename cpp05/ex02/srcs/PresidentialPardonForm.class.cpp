#include "PresidentialPardonForm.class.hpp"
#include "Bureaucrat.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form::Form(), _name("Shrubby"), _target(target), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target): _target(target), _name(name), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): _name("Shrubby"), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " PresidentialPardonForm constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
	
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		_signed = rhs._signed;
		// _name = rhs._name;
		// _sign_grade = rhs._sign_grade;
		// _execute_grade = rhs._execute_grade;

	}
	return *this;
}

std::string	PresidentialPardonForm::getName() const {
	return _name;
}

int	PresidentialPardonForm::getSignGrade(){
	return _sign_grade;
}

int	PresidentialPardonForm::getExecuteGrade(){
	return _execute_grade;
}

std::ostream &	operator<<(std::ostream & ostr, PresidentialPardonForm const & var)
{
	ostr << "PresidentialPardonForm name: " << var.getName() << ", signature grade = " << var.getSignGrade() << ", execution grade = " << var.getExecuteGrade();
	return (ostr);
}

int	PresidentialPardonForm::execute(Bureaucrat const& executor) const{
	try{
		if (executor.getSigned() == false)
			throw std::exception();
	}
	catch(std::exception& e){
		std::cout << _name << " not signed yet" << std::endl;
		return 1;
	}
	try{
		if (executor.getExecuteGrade() > _execute_grade)
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