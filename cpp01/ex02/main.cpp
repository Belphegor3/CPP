#include <string>
#include <iostream>
/*
Les références sont souvent utilisées pour les arguments de fonction ou pour retourner une valeur d'une fonction,
tandis que les pointeurs sont souvent utilisés pour passer des informations par adresse ou pour créer des objets dynamiques.
*/

int	main(void){
	std::string	test = "HI THIS IS BRAIN";
	std::string*	stringPTR = &test;
	std::string&	stringREF = test;

	std::cout << "Les addresses sont :" << std::endl;
	std::cout << &test << std::endl;
	std::cout << stringPTR << std::endl; 
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Les valeurs sont :" << std::endl;
	std::cout << test << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}