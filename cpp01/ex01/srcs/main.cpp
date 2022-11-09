#include "Zombie.class.hpp"

int	main(void){
	Zombie* Zombie_heap = zombieHorde(5, "Bob");

	delete [] Zombie_heap;
	return (0);
}