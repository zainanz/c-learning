/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:43:59 by zali              #+#    #+#             */
/*   Updated: 2025/09/29 16:38:47 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	// Weapon ak;

	// std::string ak_type = "rifle";
	// std::cout << "OR: AK_TYPE: " << ak_type << ", ADDR: " << &ak_type << std::endl;
	// ak.setType(ak_type);
	// ak_type = "sniper";
	// std::cout << "1GET: AK_TYPE: " << ak_type << ", ADDR: " << &ak_type << std::endl;
	// ak_type = ak.getType();
	// std::cout << "1GET: AK_TYPE: " << ak_type << ", ADDR: " << &ak_type << std::endl;
	// std::cout << "2GET: AK_TYPE: " << ak_type << ", ADDR: " << &ak_type << std::endl;
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
}