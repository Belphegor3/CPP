#include "RobotomyRequestForm.class.hpp"
#include "Bureaucrat.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): _name("Shrubby"), _target(target), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target): _target(target), _name(name), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): _name("Shrubby"), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " RobotomyRequestForm constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
	
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
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

std::string	RobotomyRequestForm::getName() const {
	return _name;
}

int	RobotomyRequestForm::getSignGrade(){
	return _sign_grade;
}

int	RobotomyRequestForm::getExecuteGrade(){
	return _execute_grade;
}

std::ostream &	operator<<(std::ostream & ostr, RobotomyRequestForm const & var)
{
	ostr << "RobotomyRequestForm name: " << var.getName() << ", signature grade = " << var.getSignGrade() << ", execution grade = " << var.getExecuteGrade();
	return (ostr);
}

int	RobotomyRequestForm::execute(Bureaucrat const& executor) const{
	static int	i = 0;
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
	/*		bruit de perceuse et srand(time) lance une seule fois			*/
	if (i++ == 0)
		srand(time(NULL));
	int	robotomised = rand() % 2;
	if (robotomised == 0)
		std::cout << _target << " has been succesfully robotomised" << std::endl;
	else
		std::cout << _target << " robotomisation failed" << std::endl;
	return 0;
}