#include "Zombie.class.hpp"

void	randomChump(std::string name)
{
	Zombie	Zombies = Zombie(name);

	Zombies.announce();
}