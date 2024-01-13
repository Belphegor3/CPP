#include "Form.class.hpp"
#include "Bureaucrat.class.hpp"

Form::Form(std::string target, int s_grade, int e_grade): _name(target), _sign_grade(s_grade), _execute_grade(e_grade), _signed(false){
}

Form::Form(Form const & rhs): _name(rhs._name), _sign_grade(rhs._sign_grade), _execute_grade(rhs._execute_grade){
	_signed = rhs._signed;
}

Form::~Form(){
}

std::string	Form::getName() const {
	return _name;
}

int	Form::getSignGrade() const {
	return _sign_grade;
}

bool	Form::getSigned() const {
	return _signed;
}

void	Form::setSigned(bool sign){
	_signed = sign;
}

int	Form::getExecuteGrade() const {
	return _execute_grade;
}

void	Form::beSigned(Bureaucrat const& random){
	int	i = random.getsGrade();
	try{
		if (i < 1)
			throw GradeTooHighException();
	}
	catch(GradeTooHighException & e){
		e.what();
	}
	try{
		if (i > 150 || i > _sign_grade)
			throw GradeTooLowException();
	}
	catch(GradeTooLowException & e){
		e.what();
	}
	if (i > 0 && i < 151 && i < _sign_grade)
		_signed = true;
}

int	Form::execute(Bureaucrat const & executor) const{
	(void)executor;
	std::cout << "you can't execute Form which is a model for all types of form" << std::endl;
	return 0;
}

std::ostream &	operator<<(std::ostream & ostr, Form const & var)
{
	ostr << "Form name: " << var.getName() << ", signature grade = " << var.getSignGrade();
	ostr << ", execution grade = " << var.getExecuteGrade() << ". " << (var.getSigned() == true ? "Signed" : "NonSigned");
	return (ostr);
}