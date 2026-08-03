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

#include "FragTrap.hpp"
void	TrapDetails(const FragTrap& other){
	std::cout << "other's Details {name_: " << other.getName() << ", damage_: " << other.getDamage() << ", hitpoint_: " << other.getHitpoint() << ", energy_: " << other.getEnergy() << "}" << std::endl;
}

int	main(void)
{
	FragTrap ft;
	ft.setName("FirstTrap");
	TrapDetails(ft);
	ft.highFivesGuys();

	std::cout << std::endl ;
	std::cout << std::endl ;

	FragTrap b(ft);
	b.setName("SecondTrap");
	TrapDetails(b);
	b.highFivesGuys();

	std::cout << std::endl ;
	std::cout << std::endl ;
	return (0);
}