// #include "Bureaucrat.class.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"
// #include "ShrubberyCreationForm.class.hpp"
// #include "RobotomyRequestForm.class.hpp"
// #include "PresidentialPardonForm.class.hpp"
#include "Intern.class.hpp"

int	main(void)
{
	try
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}