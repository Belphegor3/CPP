#include "convert.hpp"
std::string errors[6] = { "+inf", "+inff", "-inf", "-inff", "nan", "nanf" };

int	deal_with_special_types(std::string av){
	if (av[0] == '-'){
		if (av.compare(errors[2]) == 0)
			return (MINF);
		else if (av.compare(errors[3]) == 0)
			return (MINFF);
		else
			return (ERROR);
	}
	if (av[0] == '+'){
		if (av.compare(errors[0]) == 0)
			return (PINF);
		else if (av.compare(errors[1]) == 0)
			return (PINFF);
		else
			return (ERROR);
	}
	if (av[0] == 'n'){
		if (av.compare(errors[4]) == 0)
			return (NAN);
		else if (av.compare(errors[5]) == 0)
			return (NANF);
		else
			return (ERROR);
	}
	return 1;
}

int	deal_with_normal_types(std::string av){
	std::size_t i = 0;

	if (av[0] == '-')
		i++;
	while (av[i]){
		if (isdigit(av[i]))
			i++;
		else
			break ;
	}
	if (i == av.length())
		return (INT);
	else if (av[i++] == '.'){
		while (av[i]){
			if (isdigit(av[i]))
				i++;
			else
				break;
		}
		if (i == av.length())
			return (DOUBLE);
		else if (av[i] == 'f' && !av[i + 1])
			return (FLOAT);
		else
			return (ERROR);
	}
	return (ERROR);
}

int	deal_with_args(std::string av){
	if (av.length() == 0)
		return (std::cout << "./convert can't take NULL parameter" << std::endl, ERROR);
	if (isalpha(av[0]) && !av[1])
		return (CHAR);
	if (!isdigit(av[0]) && av[0] != '-' && av[0] != '+' && av[0] != 'n')
		return (ERROR);
	if (av[0] == '+' || (av[0] == '-' && !isdigit(av[1])) || av[0] == 'n')
		return (deal_with_special_types(av));
	return (deal_with_normal_types(av));
}

int	main(int ac, char **av){
	if (ac != 2)
		return (std::cout << "./convert takes 1 parameter" << std::endl, 1);
	int	type = deal_with_args(av[1]);
	if (type == ERROR)
		return (std::cout << "enter a valid input which is a char, an int, a double or a float" << std::endl, 1);
	if (type > 3)
		return (special_display(type), 0);
	double	res = strtod(av[1], NULL);
	switch (type)
	{
		case CHAR:
			char_display(av[1][0]);
			break;
		case INT:
			int_display(res);
			break;
		case FLOAT:
			float_display(res, precision(av[1]));
			break;
		case DOUBLE:
			double_display(res, precision(av[1]));
			break;
		default:
			break;
	}
}