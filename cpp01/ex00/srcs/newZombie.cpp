#include "Zombie.class.hpp"

Zombie*	newZombie(std::string name){
	Zombie*	Zombies = new Zombie(name);

	Zombies->announce();
	return (Zombies);
}