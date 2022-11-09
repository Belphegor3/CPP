/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:50:59 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/18 19:21:26 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie(){
	std::cout << "Constructor Zombie called" << std::endl;
	return ;
}

Zombie::~Zombie(){
	std::cout << "Destructor " << _name <<  " called" << std::endl;
	return ;
}

void	Zombie::announce(int i){
	std::cout << this->_name << " " << i << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string myname){
	this->_name = myname;
}
