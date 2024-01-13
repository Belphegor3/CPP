#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

Bureaucrat::Bureaucrat(): _name("Nerd"){
	std::cout << "Default " << _name << " Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name){
	std::cout << "Default " << _name << " Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name){
		if (grade > 150)
			throw GradeTooLowException();
		if (grade < 1)
			throw GradeTooHighException();
		_grade = grade;
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
		if (grade > 150)
			throw GradeTooLowException();
		if (grade < 1)
			throw GradeTooHighException();
		_grade = grade;
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src){
	std::cout << "Default " << _name << " Bureaucrat constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat Destructor called" << std::endl;
	
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat &	Bureaucrat::operator++()
{
	std::cout << "++ assignement operator called" << std::endl;
		if (_grade < 2)
			throw GradeTooHighException();
		else
			_grade -= 1;
	return *this;
}

Bureaucrat &	Bureaucrat::operator--()
{
	std::cout << "-- assignement operator called" << std::endl;
		if (_grade > 149)
			throw GradeTooLowException();
		else
			_grade += 1;
	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::setGrade(int i){
		if (i < 1)
			throw GradeTooHighException();
		if (i > 150)
			throw GradeTooLowException();
		_grade = i;
}

void	Bureaucrat::signForm(Form const &form){
	int		grade = this->getGrade();
	int		allow = form.getSignGrade();
	bool	sign = form.getSigned();
	std::string	name = this->getName();
	std::string form_name = form.getName();

	if (sign == true)
		std::cout << name << " signed " << form_name << std::endl;
	else{
		if (grade <= allow)
			std::cout << name << " couldn't sign " << form_name << " because you didn't use function Form::beSigned yet" << std::endl;
		else
			std::cout << name << " couldn't sign " << form_name << " because grade is too low" << std::endl;
	}
}