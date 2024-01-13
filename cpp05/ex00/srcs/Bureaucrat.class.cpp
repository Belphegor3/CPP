#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(): _name("Nerd"), _grade(140){
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(140){
	std::cout << "Default Bureaucrat constructor called" << std::endl;
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
	std::cout << "Default Bureaucrat constructor called" << std::endl;
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

int	Bureaucrat::getGrade() const{
	return _grade;
}

void	Bureaucrat::setGrade(int i){
	if (i < 1)
		throw GradeTooHighException();
	if (i > 150)
		throw GradeTooLowException();
	_grade = i;
}

std::ostream &	operator<<(std::ostream & ostr, Bureaucrat const & var){
	ostr << var.getName() << ", bureaucrat grade " << var.getGrade() << std::endl;
	return (ostr);
}