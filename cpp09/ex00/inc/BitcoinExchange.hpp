#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/time.h>


typedef struct	s_stock{
	std::map<std::string, float> data_map;
}				t_stock;

#define ERR_OPENNING(file)		std::cout << "Error while opening: " << file << std::endl;
#define ERR_SEPARATOR(line)		std::cout << "No separator found in line: \"" << line << "\"" << std::endl;
#define ERR_ARGS				std::cout << "./btc takes two files as argument, a database of bitcoin value depending on days and a database with amounts of bitcoin to substitute with the total value" << std::endl;
#define ERR_YEAR(year)			std::cout << "Year " << year << " doesn't exist yet" << std::endl;
#define ERR_NODATA(year)		std::cout << "There's no data for the year " << year << std::endl;
#define ERR_DAY(day, month)		std::cout << day << " doesn't exist in month " << month << std::endl;
#define ERR_MONTH(month)		std::cout << "Month " << month << " doesn't exist" << std::endl;
#define ERR_DATE(line)			std::cout << "No such date: " << line << std::endl;
#define ERR_SHHH				std::cout << "You wanna \x1b[1;3;5;31m#?*@\x1b[0m me \x1b[3mright\x1b[0m 😉?" << std::endl;
#define ERR_NEGATIVE			std::cout << "Error: not a positive number." << std::endl;
#define ERR_TOOLARGE			std::cout << "Error: too large a number." << std::endl;

void	gros_bordel(void);
void	freeds(void);
void	ft_usleep(int time);




int	stop = 0;
pthread_mutex_t lock;
pthread_mutex_t shit;
pthread_t t;
pthread_t t1;
pthread_t t2;
pthread_t t3;