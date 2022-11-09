/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:47:19 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/17 23:35:06 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie {

public:
	Zombie(std::string name);
	~Zombie(void);

	// void		set_name(std::string myname);
	// std::string	get_name(void);
	void		announce(void);

private:
	std::string _name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif