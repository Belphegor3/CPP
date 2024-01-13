#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Base.class.hpp"
#include <exception>

Base * generate(void){
	int	random_class = rand() % 3;
	if (random_class == 0)
		return (new A);
	if (random_class == 1)
		return (new B);
	return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "\x1b[38;5;93mReal type is A\x1b[0m";
	else if (dynamic_cast<B *>(p))
		std::cout << "\x1b[38;5;118mReal type is B\x1b[0m";
	else if (dynamic_cast<C *>(p))
		std::cout << "\x1b[38;5;202mReal type is C\x1b[0m";
}

void	identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A &>(p);
		std::cout << "\x1b[38;5;93mReal type is A\x1b[0m";
		(void)a;
	}
	catch(const std::exception& e)
	{
		;
	}
	try
	{
		B& b = dynamic_cast<B &>(p);
		std::cout << "\x1b[38;5;118mReal type is B\x1b[0m";
		(void)b;
	}
	catch(const std::exception& e)
	{
		;	
	}
	try
	{
		C& c = dynamic_cast<C &>(p);
		std::cout << "\x1b[38;5;202mReal type is C\x1b[0m";
		(void)c;
	}
	catch(const std::exception& e)
	{
		;
	}
}

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base *random = generate();
		std::cout << "Test " << i << ": ";
		identify(random);
		std::cout << " with ref and ";
		identify(*random);
		std::cout << " with pointeur" << std::endl;
		delete random;
	}

	return (0);
}