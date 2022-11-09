#include <iostream>
#include <cstring>
#include <cctype>

int	main(int ac, char **av){		
	int	i, j;
	
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
	i = 1;
	while (av[i]){
		j = 0;
		while (av[i][j]){
			std::cout << (char)toupper(av[i][j++]);
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
