#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap slave("Clap");
	ClapTrap slave2("Robot");

	slave.attack("Robot");
	slave2.takeDamage(2);
	slave2.beRepaired(1);
}