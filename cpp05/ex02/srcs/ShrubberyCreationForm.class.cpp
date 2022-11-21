#include "ShrubberyCreationForm.class.hpp"
#include "Bureaucrat.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _name("Shrubby"), _target(target), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target): _target(target), _name(name), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): _name("Shrubby"), _sign_grade(145), _execute_grade(137){
	std::cout << "Default " << _name << " ShrubberyCreationForm constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
	
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
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

std::string	ShrubberyCreationForm::getName() const {
	return _name;
}

int	ShrubberyCreationForm::getSignGrade(){
	return _sign_grade;
}

int	ShrubberyCreationForm::getExecuteGrade(){
	return _execute_grade;
}

std::ostream &	operator<<(std::ostream & ostr, ShrubberyCreationForm const & var)
{
	ostr << "ShrubberyCreationForm name: " << var.getName() << ", signature grade = " << var.getSignGrade() << ", execution grade = " << var.getExecuteGrade();
	return (ostr);
}

int	ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
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
	/*		dessiner arbre binaire			*/
	std::string replaced = _target;
	replaced += "_shrubbery";
	std::ofstream outfile;
	outfile.open(replaced.c_str());
	if (!outfile.good()){
		std::cout << "open failed" << std::endl;
		return 1;
	}
	outfile << "               ,@@@@@@@,\n	   ,,,.   ,@@@@@@/@@,  .oo8888o.\n   	,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	return 0;
}