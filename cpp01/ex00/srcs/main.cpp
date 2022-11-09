#include "Zombie.class.hpp"

int	main(void){
	Zombie* Zombie_heap = newZombie("Bob");
	randomChump("Jim");
	delete Zombie_heap;
	return (0);
}