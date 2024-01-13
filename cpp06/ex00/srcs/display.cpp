#include "convert.hpp"
std::string errorss[6] = { "+inf", "+inff", "-inf", "-inff", "nan", "nanf" };

void	special_display(int which){
	which -= 4;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (which % 2 == 0){
		std::cout << "float: " << errorss[which + 1] << std::endl;
		std::cout << "double: " << errorss[which] << std::endl;
	}
	else{
		std::cout << "float: " << errorss[which] << std::endl;
		std::cout << "double: " << errorss[which - 1] << std::endl;
	}
}

void	char_display(char c){
	if (static_cast<int>(c) < 33 || static_cast<int>(c) > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout.precision(1);
	std::cout << "float: " << std::fixed << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(c) << std::endl;
	
}

void	int_display(double i){
	if (static_cast<int>(i) < 33 || static_cast<int>(i) > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	if (i >= -2147483648 && i <= 2147483647)
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
	std::cout.precision(1);
	std::cout << "float: " << std::fixed << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(i) << std::endl;
}

void	float_display(double f, int precision){
	if (static_cast<int>(f) < 33 || static_cast<int>(f) > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	if (f >= -2147483648 && f <= 2147483647)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
	std::cout.precision(precision - 1);
	std::cout << "float: " << std::fixed << static_cast<float>(f) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(f) << std::endl;
	
}

void	double_display(double d, int precision){
	if (static_cast<int>(d) < 33 || static_cast<int>(d) > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	if (d >= -2147483648 && d <= 2147483647)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
	std::cout.precision(precision);
	std::cout << "float: " << std::fixed << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(d) << std::endl;
}

int	precision(std::string av){
	return (static_cast<int>(av.length()) - static_cast<int>(av.find('.')) - 1);
}