#include "RobotomyRequestForm.class.hpp"
// #include "Bureaucrat.class.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form(target, 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): Form(src), _target(src._target){
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return *this;
}

std::ostream &	operator<<(std::ostream & ostr, RobotomyRequestForm const & var)
{
	ostr << "RobotomyRequestForm name: " << var.getName() << ", signature grade = " << var.getSignGrade() << ", execution grade = " << var.getExecuteGrade();
	return (ostr);
}

int	RobotomyRequestForm::execute(Bureaucrat const& executor) const{
	static int	i = 0;
	try{
		if (this->getSigned() == false)
			throw std::exception();
	}
	catch(std::exception& e){
		std::cout << _target << " not signed yet" << std::endl;
		return 1;
	}
	try{
		if (executor.geteGrade() > this->getExecuteGrade())
			throw std::exception();
	}
	catch(std::exception& e){
		std::cout << executor.getName() << " execute grade too low" << std::endl;
		return 1;
	}
	/*		bruit de perceuse et srand(time) lance une seule fois			*/
	if (i++ == 0)
		srand(time(NULL));
	int	robotomised = rand() % 100000;
	if (robotomised % 2 == 0)
		std::cout << _target << " has been succesfully robotomised" << std::endl;
	else
		std::cout << _target << " robotomisation failed" << std::endl;
	return 0;
}