#include "Bureaucrat.class.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int	main(void)
{
	{
		{
			std::cout << std::endl;
			std::cout << YELLOW << "========== NAMED SHRUBBERYFORM ==========" << RESET << std::endl;
			ShrubberyCreationForm SF76("SF76");
			std::cout << SF76;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO SIGN FORM =========" << RESET << std::endl;
		{
			ShrubberyCreationForm	SF86("SF86");
			Bureaucrat				bob("Bob", 146, 50);

			bob.signForm(SF86);
		}
		std::cout << std::endl;

		std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO EXECUTE FORM ==========" << RESET << std::endl;
		{
			ShrubberyCreationForm	SF27("SF27");
			Bureaucrat				bob("Bob", 1, 80);

			SF27.beSigned(bob);
			bob.signForm(SF27);
			bob.executeForm(SF27);
		}
		std::cout << std::endl;

		std::cout << YELLOW << "========== ATTEMPTING TO EXECTUTE A FORM NOT SIGNED =========" << RESET << std::endl;
		{
			ShrubberyCreationForm	SF72("SF72");
			Bureaucrat				john("John", 110, 150);
			
			john.executeForm(SF72);
		}
		std::cout << std::endl;
	
		std::cout << YELLOW << "========== ALL GOOD HERE ==========" << RESET << std::endl;
		{
			ShrubberyCreationForm	SF66("SF66");
			Bureaucrat				jack("Jack", 24, 1);
		
			SF66.beSigned(jack);
			jack.signForm(SF66);
			jack.executeForm(SF66);
		}
		std::cout << std::endl;
	}
	{
		{	
			std::cout << std::endl;
			std::cout << YELLOW << "========== NAMED ROBOTOMYFORM ==========" << RESET << std::endl;
			RobotomyRequestForm RF76("RF76");
			std::cout << RF76;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO SIGN FORM =========" << RESET << std::endl;
		{
			RobotomyRequestForm	RF86("RF86");
			Bureaucrat			bob("Bob", 73, 1);

			bob.signForm(RF86);
		}
		std::cout << std::endl;

		std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO EXECUTE FORM ==========" << RESET << std::endl;
		{
			RobotomyRequestForm	RF27("RF27");
			Bureaucrat			bob("Bob", 46, 150);

			RF27.beSigned(bob);
			bob.signForm(RF27);
			bob.executeForm(RF27);
		}
		std::cout << std::endl;

		std::cout << YELLOW << "========== ATTEMPTING TO EXECTUTE A FORM NOT SIGNED =========" << RESET << std::endl;
		{
			RobotomyRequestForm	RF72("RF72");
			Bureaucrat			john("John", 40, 110);
			
			john.executeForm(RF72);
		}
		std::cout << std::endl;
	
		std::cout << YELLOW << "========== ALL GOOD HERE ==========" << RESET << std::endl;
		{
			RobotomyRequestForm	RF66("RF66");
			Bureaucrat			jack("Jack", 40, 100);
		
			RF66.beSigned(jack);
			jack.signForm(RF66);
			jack.executeForm(RF66);
			jack.executeForm(RF66);
			jack.executeForm(RF66);
			jack.executeForm(RF66);
			jack.executeForm(RF66);
			jack.executeForm(RF66);
		}
		std::cout << std::endl;
	}
	{
		{	
			std::cout << std::endl;
			std::cout << YELLOW << "========== NAMED PRESIDENTIALPARDONFORM ==========" << RESET << std::endl;
			PresidentialPardonForm PP76("PP76");
			std::cout << PP76;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO SIGN FORM =========" << RESET << std::endl;
		{
			PresidentialPardonForm	PP86("PP86");
			Bureaucrat				bob("Bob", 150, 78);

			PP86.beSigned(bob);
			bob.signForm(PP86);
		}
		std::cout << std::endl;

		std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO EXECUTE FORM ==========" << RESET << std::endl;
		{
			PresidentialPardonForm	PP27("PP27");
			Bureaucrat				bob("Bob", 6, 150);

			PP27.beSigned(bob);
			bob.signForm(PP27);
			bob.executeForm(PP27);
		}
		std::cout << std::endl;

		std::cout << YELLOW << "========== ATTEMPTING TO EXECTUTE A FORM NOT SIGNED =========" << RESET << std::endl;
		{
			PresidentialPardonForm	PP72("PP72");
			Bureaucrat				john("John", 3, 87);
			
			john.executeForm(PP72);
		}
		std::cout << std::endl;
	
		std::cout << YELLOW << "========== ALL GOOD HERE ==========" << RESET << std::endl;
		{
			PresidentialPardonForm	PP66("PP66");
			Bureaucrat				jack("Jack", 3, 7);
		
			PP66.beSigned(jack);
			jack.signForm(PP66);
			jack.executeForm(PP66);
		}
	}
}