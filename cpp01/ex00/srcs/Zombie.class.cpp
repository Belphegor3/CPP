/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:50:59 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/17 23:20:43 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie(std::string name) : _name(name){
	std::cout << "Constructor Zombie called" << std::endl;
	return ;
}

Zombie::~Zombie(){
	std::cout << "Destructor " << _name <<  " called" << std::endl;
	return ;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// void	Zombie::set_name(std::string myname){
// 	_name = myname;
// }

// std::string	Zombie::get_name(void){
// 	return (_name);
// }