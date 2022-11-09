#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap slave("Clap");
	ScavTrap slave2;

	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave.attack(slave2.getName());
	slave2.takeDamage(20);
	slave2.beRepaired(1000);
	slave2.beRepaired(1000);
	slave.guardGate();
}