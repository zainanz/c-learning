/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:02 by zali              #+#    #+#             */
/*   Updated: 2025/09/29 16:40:02 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string name): _name(name), _weapon(NULL){};
HumanB::HumanB(std::string name, Weapon &weap): _name(name), _weapon(&weap){};

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon &weap)
{
	this->_weapon = &weap;
}