#include "FragTrap.hpp"

int	main(void)
{
	FragTrap slave("Clap");
	FragTrap slave2;

	slave.attack(slave2.getName());
	slave2.takeDamage(30);
	slave.attack(slave2.getName());
	slave2.takeDamage(30);
	slave.attack(slave2.getName());
	slave2.takeDamage(30);
	slave.attack(slave2.getName());
	slave2.takeDamage(30);
	slave.attack(slave2.getName());
	slave2.takeDamage(30);
	slave2.beRepaired(1000);
	slave2.beRepaired(1000);
	slave.attack(slave2.getName());
	slave2.takeDamage(30);
	slave2.beRepaired(15);
	slave.highFivesGuys();
}