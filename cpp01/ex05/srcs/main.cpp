#include "Harl.class.hpp"

int	main(int ac, char **av)
{
	Harl	random;
	if (ac != 2)
		return (std::cout << "./Harl takes one argument which is a level between DEBUG, INFO, WARNING, ERROR" << std::endl, 1);
	return (random.complain(av[1]), 0);
}