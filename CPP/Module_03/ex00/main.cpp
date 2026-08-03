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

static void ClapTrapAttackDamage(ClapTrap& c1, ClapTrap& c2){
	c1.attack(c2.getName());
	c2.takeDamage(c1.getDamage());
}
int	main(void)
{
	ClapTrap Carl("Carl");
	Carl.setDamage(2);

	ClapTrap Carl2(Carl);

	std::cout << "Carl2 stole Carl's personality. [Carl2's Name: " << Carl.getName() << "]" << std::endl; 
	Carl2.setName("Fake Carl");
	std::cout << "Fake Carl2 was detected and renamed to " << Carl2.getName() << std::endl;
	Carl2 = Carl;
	std::cout << "Fake Carl successfully stole Carl's identity again using assignment operator! [Fake Carl's Name: " << Carl2.getName() <<  "]" << std::endl;

	std::cout << "======== Carl battles Fake Carl ========" << std::endl; 
	Carl2.setName("Fake Carl");
	ClapTrapAttackDamage(Carl, Carl2);

	Carl2.beRepaired(1);
	Carl.setDamage(50);
	ClapTrapAttackDamage(Carl2, Carl);
	ClapTrapAttackDamage(Carl, Carl2);
	ClapTrapAttackDamage(Carl, Carl2);
	Carl.setEnergy(0);
	Carl.attack(Carl2.getName());
	Carl.attack(Carl2.getName());
	Carl.attack(Carl2.getName());

	return (0);
}