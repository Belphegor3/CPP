/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:45:03 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/18 01:10:01 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void){
	return ;
}

Contact::~Contact(void){
	return ;
}

void	Contact::show_contact(void){
	std::cout << "\033[1;38;5;26mFirst name: \033[0m" << this->_first_name << std::endl;
	std::cout << "\033[1;38;5;26mLast name: \033[0m" << this->_last_name << std::endl;
	std::cout << "\033[1;38;5;26mNickname: \033[0m" << this->_nickname << std::endl;
	std::cout << "\033[1;38;5;26mPhone number: \033[0m" << this->_phone_number << std::endl;
	std::cout << "\033[1;38;5;26mDarkest secret: \033[0m" << this->_darkest_secret << std::endl;
}

int	is_number(std::string line)
{
	int	i = 0;
	std::string::const_iterator it = line.begin();

	while (it != line.end())
	{
		if (line.at(i) < 48 || line.at(i) > 57)
			return (EXIT_FAILURE);
		i++;
		it++;
	}
	if (i < 2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

std::string	Contact::get_contact(char which){
	switch (which){
		case 'f':
			return (this->_first_name);
		case 'l':
			return (this->_last_name);
		case 'n':
			return (this->_nickname);
		case 'p':
			return (this->_phone_number);
		case 'd':
			return (this->_darkest_secret);
		default:
			return ("");
	}
}

void	Contact::set_contact(void){
	std::cout << "\033[38;5;87mWhat is your first name? \033[0m";
	while (1){
		getline(std::cin, this->_first_name);
		if (std::cin.eof())
			_exit(1);
		if (this->_first_name.empty()){
			std::cout << "\033[1;38;5;88mNo input, insert an input\033[0m" << std::endl;
		}
		else{
			break ;
		}
	}
	std::cout << "\033[38;5;85mWhat is your last name? \033[0m";
	while (1){
		getline(std::cin, this->_last_name);
		if (std::cin.eof())
			_exit(1);
		if (this->_last_name.empty()){
			std::cout << "\033[1;38;5;88mNo input, insert an input\033[0m" << std::endl;
		}
		else{
			break ;
		}
	}
	std::cout << "\033[38;5;227mWhat is your nickname? \033[0m";
	while (1){
		getline(std::cin, this->_nickname);
		if (std::cin.eof())
			_exit(1);
		if (this->_nickname.empty()){
			std::cout << "\033[1;38;5;88mNo input, insert an input\033[0m" << std::endl;
		}
		else{
			break ;
		}
	}
	std::cout << "\033[38;5;205mWhat is your phone number? \033[0m";
	while (1){
		getline(std::cin, this->_phone_number);
		if (std::cin.eof())
			_exit(1);
		if (this->_phone_number.empty()){
			std::cout << "\033[1;38;5;88mNo input, insert an input\033[0m" << std::endl;
		}
		else if (is_number(this->_phone_number)){
			std::cout << "\033[1;38;5;88mI feel like it's a fake 🤨\033[0m" << std::endl << "\033[38;5;205mGive me a phone number please\033[0m" << std::endl;
		}
		else{
			break ;
		}
	}
	std::cout << "\033[38;5;171mWhat is your darkest secret? \033[0m";
	while (1){
		getline(std::cin, this->_darkest_secret);
		if (std::cin.eof())
			_exit(1);
		if (this->_darkest_secret.empty()){
			std::cout << "\033[1;38;5;88mNo input, insert an input\033[0m" << std::endl;
		}
		else{
			break ;
		}
	}
}

void	Contact::reset_contact(void){
	this->_first_name.clear();
	this->_last_name.clear();
	this->_nickname.clear();
	this->_phone_number.clear();
	this->_darkest_secret.clear();
}