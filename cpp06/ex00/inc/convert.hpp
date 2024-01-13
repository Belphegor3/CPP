#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <string.h>

enum Type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PINF,
	PINFF,
	MINF,
	MINFF,
	NAN,
	NANF,
	ERROR
};

void	special_display(int which);
void	char_display(char c);
void	double_display(double d, int precision);
void	float_display(double f, int precision);
void	int_display(double i);
int		precision(std::string av);

#endif