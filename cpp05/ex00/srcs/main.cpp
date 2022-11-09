#include "Bureaucrat.class.hpp"

int	main(){
	Bureaucrat	test;

	test.setGrade(50);
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	--test;
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	++test;
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	test.setGrade(151);
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	test.setGrade(1);
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	++test;
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
}