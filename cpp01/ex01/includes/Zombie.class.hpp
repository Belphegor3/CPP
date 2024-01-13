/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:47:19 by lfchouch          #+#    #+#             */
/*   Updated: 2023/08/23 01:58:20 by lfchouch         ###   ########.fr       */
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