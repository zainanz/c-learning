/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:37:36 by zali              #+#    #+#             */
/*   Updated: 2025/09/28 17:39:52 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP
#include <iostream>
class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
	private:
		std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif