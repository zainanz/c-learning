/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:42:56 by zali              #+#    #+#             */
/*   Updated: 2026/06/11 11:42:58 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *ptr;

	std::cout << "Dragon Veldora Tempest: **ROARRRRRRRRRRRRRR**\n";
	ptr = zombieHorde(5, "trovo");
	ptr->announce();
	delete [] ptr;
}
