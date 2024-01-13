#include "Form.class.hpp"

Form::Form(): _name("42"), _sign_grade(150), _execute_grade(150), _signed(false){
	std::cout << "Default " << _name << " Form constructor called" << std::endl;
}

Form::Form(std::string name): _name(name), _sign_grade(150), _execute_grade(150), _signed(false){
	std::cout << "Default " << _name << " Form constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int execute_grade): _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade), _signed(false){
	std::cout << "Default " << _name << " Form constructor called" << std::endl;
}

Form::Form(Form const & src): _name("42"), _sign_grade(150), _execute_grade(150), _signed(false){
	std::cout << "Default " << _name << " Form constructor called" << std::endl;
	*this = src;
}

Form::~Form(){
	std::cout << "Form Destructor called" << std::endl;
	
}

Form &	Form::operator=(Form const & rhs)
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
	int	i = random.getGrade();
		if (i < 1)
			throw GradeTooHighException();
		if (i > 150 || i > _sign_grade)
			throw GradeTooLowException();
		_signed = true;
}


/**/
std::ostream &	operator<<(std::ostream & ostr, Form const & var)
{
	ostr << "Form name: " << var.getName() << ", signature grade = " << var.getSignGrade();
	ostr << ", execution grade = " << var.getExecuteGrade() << ". " << (var.getSigned() == true ? "Signed" : "NonSigned");
	return (ostr);
}

/**/