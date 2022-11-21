#include "AForm.class.hpp"

AForm::~AForm(){
	std::cout << "AForm Destructor called" << std::endl;
	
}

std::string	AForm::getName() const {
	return _name;
}

int	AForm::getSignGrade() const {
	return _sign_grade;
}

bool	AForm::getSigned() const {
	return _signed;
}

void	AForm::setSigned(bool sign){
	_signed = sign;
}

int	AForm::getExecuteGrade() const {
	return _execute_grade;
}

void	AForm::GradeTooHighException(){
	std::cout << "Grade is too high" << std::endl;
}

void	AForm::GradeTooLowException(){
	std::cout << "Grade is too low" << std::endl;
}

void	AForm::beSigned(Bureaucrat const& random){
	int	i = random.getGrade();
	try{
		if (i < 1)
			throw std::exception();
	}
	catch(std::exception & GradeTooHighException){
		this->GradeTooHighException();
	}
	try{
		if (i > 150 || i > _sign_grade)
			throw std::exception();
	}
	catch(std::exception & GradeTooLowException){
		this->GradeTooLowException();
	}
	if (i > 0 && i < 151 && i < _sign_grade)
		_signed = true;
}

std::ostream &	operator<<(std::ostream & ostr, AForm const & var)
{
	ostr << "AForm name: " << var.getName() << ", signature grade = " << var.getSignGrade();
	ostr << ", execution grade = " << var.getExecuteGrade() << ". " << (var.getSigned() == true ? "Signed" : "NonSigned");
	return (ostr);
}