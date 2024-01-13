#include <fstream>
#include "ShrubberyCreationForm.class.hpp"
#include "Bureaucrat.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form(target, 25, 5), _target(target){

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): Form(src), _target(src._target){
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & ostr, ShrubberyCreationForm const & var)
{
	ostr << "ShrubberyCreationForm name: " << var.getName() << ", signature grade = " << var.getSignGrade() << ", execution grade = " << var.getExecuteGrade();
	return (ostr);
}

int	ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
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