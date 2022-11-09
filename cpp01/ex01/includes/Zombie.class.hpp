/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:47:19 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/18 19:22:00 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie {

public:
	Zombie(void);
	~Zombie(void);

	void		set_name(std::string myname);
	void		announce(int i);

private:
	std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif