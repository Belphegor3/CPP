#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

Bureaucrat::Bureaucrat(): _name("Nerd"), _egrade(150), _sgrade(150){
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _egrade(150), _sgrade(150){
}

Bureaucrat::Bureaucrat(std::string name, int sgrade, int egrade): _name(name), _egrade(egrade), _sgrade(sgrade){
}

Bureaucrat::Bureaucrat(Bureaucrat const & src){
	*this = src;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	(void)rhs;
	return *this;
}

Bureaucrat &	Bureaucrat::operator++()
{
	std::cout << "++ assignement operator called" << std::endl;
	try
	{
		if (_sgrade < 2)
			throw GradeTooHighException();
		else
			_sgrade -= 1;
	}
	catch(GradeTooHighException& e)
	{
		e.what();
	}
	try
	{
		if (_egrade < 2)
			throw GradeTooHighException();
		else
			_egrade -= 1;
	}
	catch(GradeTooHighException& e)
	{
		e.what();
	}
	return *this;
}

Bureaucrat &	Bureaucrat::operator--()
{
	std::cout << "-- assignement operator called" << std::endl;
	try
	{
		if (_sgrade > 149)
			throw GradeTooLowException();
		else
			_sgrade += 1;
	}
	catch(GradeTooLowException& e)
	{
		e.what();
	}
	try
	{
		if (_egrade > 149)
			throw GradeTooLowException();
		else
			_egrade += 1;
	}
	catch(GradeTooLowException& e)
	{
		e.what();
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
			throw GradeTooHighException();
	}
	catch(GradeTooHighException & e){
		e.what();
	}
	try{
		if (i > 150)
			throw GradeTooLowException();
	}
	catch(GradeTooLowException & e){
		e.what();
	}
	if (i > 0 && i < 151)
		_egrade = i;
}

void	Bureaucrat::setsGrade(int i){
	try{
		if (i < 1)
			throw GradeTooHighException();
	}
	catch(GradeTooHighException & e){
		e.what();
	}
	try{
		if (i > 150)
			throw GradeTooLowException();
	}
	catch(GradeTooLowException & e){
		e.what();
	}
	if (i > 0 && i < 151)
		_sgrade = i;
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
	if (!form.execute(*this))
		std::cout << _name << " executed " << form.getName() << std::endl;
	else
		std::cout << _name << " didn't execute " << form.getName() << std::endl;

}