#include "Bureaucrat.class.hpp"

int	main(){
	try{
	Bureaucrat	test("bob", 140);

	std::cout << test;
	--test;
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	++test;
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	try{
	test.setGrade(151);
	}
		catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	test.setGrade(1);
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	try{
	++test;
	}
		catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << test.getName() << " has grade: " << test.getGrade() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}