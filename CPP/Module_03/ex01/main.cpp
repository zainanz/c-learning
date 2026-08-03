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

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap st("ST-1");
	std::cout << "ST's Details {name_: " << st.getName() << ", damage_: " << st.getDamage() << ", hitpoint_: " << st.getHitpoint() << ", energy_: " << st.getEnergy() << std::endl;
	ScavTrap st2(st);
	std::cout << "ST2's Details {name_: " << st2.getName() << ", damage_: " << st2.getDamage() << ", hitpoint_: " << st2.getHitpoint() << ", energy_: " << st2.getEnergy() << std::endl;
	st2.attack("Car");
	st2.guardGate();
	return (0);
}