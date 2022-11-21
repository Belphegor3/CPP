#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

Bureaucrat::Bureaucrat(): _name("Nerd"), _sgrade(150), _egrade(150){
	std::cout << "Default " << _name << " Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _sgrade(150), _egrade(150){
	std::cout << "Default " << _name << " Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int sgrade, int egrade): _name(name), _egrade(egrade), _sgrade(sgrade){
	std::cout << "Default " << _name << " Bureaucrat constructor called" << std::endl;
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
	return *this;
}

Bureaucrat &	Bureaucrat::operator++()
{
	std::cout << "++ assignement operator called" << std::endl;
	try
	{
		if (_sgrade < 2)
			throw std::exception();
		else
			_sgrade -= 1;
	}
	catch(std::exception& GradeTooHighException)
	{
		this->GradeTooHighException();
	}
	try
	{
		if (_egrade < 2)
			throw std::exception();
		else
			_egrade -= 1;
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
		if (_sgrade > 149)
			throw std::exception();
		else
			_sgrade += 1;
	}
	catch(std::exception& GradeTooLowException)
	{
		this->GradeTooLowException();
	}
	try
	{
		if (_egrade > 149)
			throw std::exception();
		else
			_egrade += 1;
	}
	catch(std::exception& GradeTooLowException)
	{
		this->GradeTooLowException();
	}
	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::geteGrade() const {
	return _egrade;
}

int	Bureaucrat::getsGrade() const {
	return _sgrade;
}

void	Bureaucrat::seteGrade(int i){
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
		_egrade = i;
}

void	Bureaucrat::setsGrade(int i){
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
		_sgrade = i;
}

void	Bureaucrat::GradeTooHighException(){
	std::cout << "Grade is too high" << std::endl;
}

void	Bureaucrat::GradeTooLowException(){
	std::cout << "Grade is too low" << std::endl;
}

void	Bureaucrat::signForm(Form const &form){
	int		grade = this->getsGrade();
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

void	Bureaucrat::executeForm(Form const & form){
	if (!form.execute())
		std::cout << _name << " executed " << form.getName() << std::endl;
	else
		std::cout << _name << " didn't execute " << form.getName() << std::endl;
}