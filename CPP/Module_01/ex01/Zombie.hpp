/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:37:36 by zali              #+#    #+#             */
/*   Updated: 2025/09/28 17:57:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP
#include <iostream>
class Zombie
{
	public:
		Zombie();
		~Zombie(void);
		void	announce(void);
		void	nameZombie(std::string name);
	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);
#endif