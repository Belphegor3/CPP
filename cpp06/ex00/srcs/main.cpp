#include <iostream>
#include <string>

enum Type{
	CHAR = 100,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	ERROR
};

std::string errors[6] = { "+inf", "+inff", "-inf", "-inff", "nan", "nanf" };

void	display(){

}

int	deal_with_special_ones(std::string av){
	if (av[0] == '-'){
		if (av.compare(errors[2]) == 0)
			return (DOUBLE);
		else if (av.compare(errors[3]) == 0)
			return (FLOAT);
		else
			return (ERROR);
	}
	if (av[0] == '+'){
		if (av.compare(errors[0]) == 0)
			return (DOUBLE);
		else if (av.compare(errors[1]) == 0)
			return (FLOAT);
		else
			return (ERROR);
	}
	if (av[0] == 'n'){
		if (av.compare(errors[4]) == 0)
			return (DOUBLE);
		else if (av.compare(errors[5]) == 0)
			return (FLOAT);
		else
			return (ERROR);
	}
}

int	deal_with_args(std::string av){
	int	i = 0;

	if (av.length() == 0)
		return (std::cout << "./convert can't take NULL parameter" << std::endl, ERROR);
	if (isalpha(av[0]) && !av[1])
		return (CHAR);
	if (!isdigit(av[0]) && av[0] != '-' && av[0] != '+' && av[0] != 'n')
		return (std::cout << "fait un effort frerot" << std::endl, ERROR);
	if (av[0] == '-'){
		if (av.compare(errors[2]) == 0)
			return (DOUBLE);
		else if (av.compare(errors[3]) == 0)
			return (FLOAT);
		else
			return (ERROR);
	}
	if (av[0] == '+'){
		if (av.compare(errors[0]) == 0)
			return (DOUBLE);
		else if (av.compare(errors[1]) == 0)
			return (FLOAT);
		else
			return (ERROR);
	}
	if (av[0] == 'n'){
		if (av.compare(errors[4]) == 0)
			return (DOUBLE);
		else if (av.compare(errors[5]) == 0)
			return (FLOAT);
		else
			return (ERROR);
	}
	while (av[i]){
		if (av[0])
			;
	}
	return (ERROR);
}

void	special_display(int which){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (which % 2 == 0){
		std::cout << "float: " << errors[which + 1] << std::endl;
		std::cout << "double: " << errors[which] << std::endl;
	}
	else{
		std::cout << "float: " << errors[which] << std::endl;
		std::cout << "double: " << errors[which - 1] << std::endl;
	}
}

void	char_display(char c){
	
}

int	main(int ac, char **av){
	if (ac != 2)
		return (std::cout << "./convert takes 1 parameter" << std::endl, 1);
	if (deal_with_args(av[1]) == -1)
		return (1);
	int	type = deal_with_args(av[1]);
	switch (type)
	{
	case 0:
		
		break;
	
	default:
		break;
	}
}