/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:11:46 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/18 18:36:50 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(int ac, char **av){
	Phonebook	phonebook;
	std::string	input;

	int	count = 0;
	int	aff_or_not_to_aff = 0;
	int	bug = 0;

	(void)av;
	std::atexit(Term::restoreTerm);
	std::cout << "\x1b[2J\x1b[H";
	if (ac != 1)
		return (std::cout << "\033[5;91mNo parameters needed\033[0m" << std::endl, 1);
	while (1){
		if (aff_or_not_to_aff == 0)
			disable_term(0);
		getline(std::cin, input);
		if (std::cin.eof())
			_exit(123);
		if (basic_display(&phonebook, &count, &aff_or_not_to_aff, input, &bug)){
			bug = 0;
			default_display(&count, &bug);
		}
	}
	return (0);
}