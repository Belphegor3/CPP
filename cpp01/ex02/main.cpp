#include <string>
#include <iostream>
// #include 

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