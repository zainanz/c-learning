/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:52:18 by zali              #+#    #+#             */
/*   Updated: 2025/09/28 17:59:19 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *z_horde;
	z_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		z_horde[i].nameZombie(name);
	return (z_horde);
}