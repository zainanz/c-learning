/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:16:13 by zali              #+#    #+#             */
/*   Updated: 2025/10/13 18:41:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	{

	ClapTrap one("oneila");

	one.attack("two");
	one.beRepaired(2);
	one.takeDamage(5);

	std::cout << "\n\n\n";
	// Setters and Getters
	ClapTrap &clappington = one; 
	clappington.setName("Claptrappington");
	std::cout << "Claptrap " << clappington.getName() << " was upgraded -> " << clappington.getName() << ".\n";
	clappington.setDamage(100);
	clappington.setEnergy(100);
	clappington.setHitpoint(500);
	std::cout << clappington.getName() << ": damage(" << clappington.getDamage() << "), energy(" << clappington.getEnergy() << "), hitpoint(" << clappington.getHitpoint() << ")\n";
	// Copy Constructors
	std::cout << "\n\n\n";
	ClapTrap copyiton;
	copyiton = clappington;
	copyiton.setName("Copyiton");
	ClapTrap copyiton2(clappington);
	copyiton2.setName("Copyiton2");
	std::cout << &copyiton << " - " << copyiton.getName() << ": damage(" << copyiton.getDamage() << "), energy(" << copyiton.getEnergy() << "), hitpoint(" << copyiton.getHitpoint() << ")\n";
	std::cout << &copyiton2 << " - " << copyiton2.getName() << ": damage(" << copyiton2.getDamage() << "), energy(" << copyiton2.getEnergy() << "), hitpoint(" << copyiton2.getHitpoint() << ")\n";
	}

	std::cout << "\n\n\n";
	std::cout << "\n\n\n";
	return (0);
}