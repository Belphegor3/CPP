#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int	main(){
	Bureaucrat	ttest("Bob");
	Form		fform("1664", 40, 60);

	try{
	std::cout << "Changement de grade" << std::endl;
	ttest.setGrade(50);
	std::cout << std::endl << "voici les informations du formulaire: " << fform << std::endl << std::endl;
	std::cout << "tentative de signature de formulaire" << std::endl;
	try{
	ttest.signForm(fform);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "utilisation de la fonction beSigned" << std::endl;
	try{
	fform.beSigned(ttest);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "voici les informations du formulaire: " << fform << std::endl << std::endl;
	std::cout << "tentative de signature de formulaire" << std::endl;
	try{
	ttest.signForm(fform);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Changement de grade" << std::endl;
	ttest.setGrade(30);
	std::cout << std::endl << "voici les informations du formulaire: " << fform << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "tentative de signature de formulaire" << std::endl;
	ttest.signForm(fform);
	std::cout << "utilisation de la fonction beSigned" << std::endl;
	fform.beSigned(ttest);
	std::cout << std::endl << "voici les informations du formulaire: " << fform << std::endl << std::endl;
	std::cout << "tentative de signature de formulaire" << std::endl;
	ttest.signForm(fform);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}