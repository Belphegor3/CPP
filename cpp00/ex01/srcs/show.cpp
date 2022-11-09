/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:51:09 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/17 22:13:53 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

std::string	over_under_equal_10(std::string name){
	std::string	res = "";
	unsigned long	j;

	if ((name.length() > 10)){
		j = 0;
		while (j < 10)
			res += name.at(j++);
		res[9] = '.';
	}
	else if (name.length() == 10){
		j = 0;
		while (j < 10)
			res += name.at(j++);
	}
	else{
		j = 0;
		while (j < name.length())
			res += name.at(j++);
	}
	return (res);
}

std::string	Phonebook::overflow_10(int i, char which)
{	
	std::string	first = this->_contacts[i].get_contact('f');
	std::string	last = this->_contacts[i].get_contact('l');
	std::string	nick = this->_contacts[i].get_contact('n');
	std::string	res;

	switch (which){
		case ('f'):
			res = over_under_equal_10(first);
			break;
		case ('l'):
			res = over_under_equal_10(last);
			break;
		case ('n'):
			res = over_under_equal_10(nick);
			break;
		default:
			break;
	}
	return (res);
}

void	Phonebook::line_format(int i, int oldest)
{
	if (i >= 0){
		std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << oldest << "|" << std::setw(10) << overflow_10(i, 'f') << "|" << std::setw(10) << overflow_10(i, 'l') << "|" << std::setw(10) << overflow_10(i, 'n') << "|" << std::endl;
	}
	else
		std::cout << "|Real Index|  _Index  |First Name| LastName | Nickname |" << std::endl;
}

void	Phonebook::show_phonebook(void)
{
	int	oldest;
	int	i = 0;

	std::cout << "________________________________________________________" << std::endl;
	if (_index > 7){
		oldest = _index - (_index % 8);
		while (i < 8)
		{
			if (i == 0){
				line_format(-1, oldest);
				std::cout << "________________________________________________________" << std::endl;
				line_format(i, oldest);
			}
			else
				line_format(i, oldest);
		i++;
		oldest++;
		if (oldest > _index)
			oldest = _index % 8 + 1;
		std::cout << "________________________________________________________" << std::endl;
		}
	}
	else{
		oldest = 0;
		while (i < _index)
		{
			if (i == 0){
				line_format(-1, oldest);
				std::cout << "________________________________________________________" << std::endl;
				line_format(i, oldest);
			}
			else
				line_format(i, oldest);
			i++;
			std::cout << "________________________________________________________" << std::endl;
			oldest++;
		}
	}
	std::cout << std::endl;
}

// 8		8		8
// 9		9		1
// 10		2		2
// 11		3		3
// 12		4		4
// 13		5		5
// 14		6		6
// 7		7		7

// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15

// 16
// 9
// 10
// 11
// 12
// 13
// 14
// 15