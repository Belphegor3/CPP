#include "iter.hpp"

int	main(void){
	int	ex[] = {0, 1, 2};
	std::string ex2[] = {"Hello", "World"};

	iter<int>(ex, 3, display);
	// iter<std::string>(ex2, 2, display);
}