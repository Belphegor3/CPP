#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(): _name("Nerd"){
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name){
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
	try
	{
		if (_grade < 2)
			throw std::exception();
		else
			_grade -= 1;
	}
	catch(std::exception& GradeTooHighException)
	{
		this->GradeTooHighException();
	}
	return *this;
}

Bureaucrat &	Bureaucrat::operator--()
{
	std::cout << "-- assignement operator called" << std::endl;
	try
	{
		if (_grade > 149)
			throw std::exception();
		else
			_grade += 1;
	}
	catch(std::exception& GradeTooLowException)
	{
		this->GradeTooLowException();
	}
	return *this;
}

std::string	Bureaucrat::getName(){
	return _name;
}

int	Bureaucrat::getGrade(){
	return _grade;
}

void	Bureaucrat::setGrade(int i){
	try{
		if (i < 1)
			throw std::exception();
	}
	catch(std::exception & GradeTooHighException){
		this->GradeTooHighException();
	}
	try{
		if (i > 150)
			throw std::exception();
	}
	catch(std::exception & GradeTooLowException){
		this->GradeTooLowException();
	}
	if (i > 0 && i < 151)
		_grade = i;
}

void	Bureaucrat::GradeTooHighException(){
	std::cout << "Grade is too high" << std::endl;
}

void	Bureaucrat::GradeTooLowException(){
	std::cout << "Grade is too low" << std::endl;
}