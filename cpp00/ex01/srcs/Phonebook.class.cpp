/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:29:54 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/18 01:10:01 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void): _index(0){
	return ;
}

Phonebook::~Phonebook(void){
	return ;
}

int	Phonebook::getIndex(void) 
{
	return (_index);
}

int	is_only_digits(std::string line)
{
	int							i = 0;

	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9')){
			std::cout << "\033[1;38;5;88m\"Real Index\" is a number\033[0m" << std::endl;
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	Phonebook::search_contact(void){
	std::string	line;
	std::string	input;
	long		value;
	int			keep_going = 0;
	
	while (1){
		keep_going = 0;
		show_phonebook();
		std::cout << "\033[1;38;5;227mWhich contact would you track? (choose with \"Real Index\")\033[0m ";
		getline(std::cin, line);
		if (is_only_digits(line))
			continue;
		if (std::cin.eof())
			_exit(255);
		value = strtol(line.c_str(), NULL, 10);
		if (this->_index <= value){
			std::cout << "\033[1;38;5;88mYou must select the contact you want to track with his \"Real Index\"\033[0m" << std::endl;
			continue;
		}
		for (int i = 0; i < 8; i++){
			if (value == i){
				std::cout << "\x1b[2J\x1b[H";
				std::cout << "\033[1;38;5;225mHere is what we've got about this contact\033[0m" << std::endl << std::endl;
				Phonebook::_contacts[i].show_contact();
				std::cout << CURSOR_OFF;
				std::cout << std::endl << std::endl << "(Type q to exit when you're done stalking or s to stalk someone else)";
				std::flush(std::cout);
				while (1){
					if (quit_or_again()){
						keep_going = 1;
						std::cout << CURSOR_ON;
						break ;
					}
					std::cout << CURSOR_ON;
					std::cout << "\x1b[2J\x1b[H";
					return ;
				}
			}
		}
		std::cout << "\x1b[2J\x1b[H";
		continue;
	}
}

void	Phonebook::add_contact(void){
	int	most_recent;
	int	oldest;

	most_recent = this->_index;
	if (this->_index > 7)
	{
		oldest = most_recent % 8;
		this->_contacts[oldest].reset_contact();
	}
	else
		oldest = most_recent;
	this->_contacts[oldest].set_contact();
	this->_index++;
}

/*
	0	8	8
	1	1	9
	2	2	2
	3	3	3
	4	4	4
	5	5	5
	6	6	6
	7	7	7
*/
