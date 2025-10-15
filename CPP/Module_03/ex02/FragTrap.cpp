/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:03:39 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 00:39:53 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
FragTrap::FragTrap(void) : ClapTrap("unnamed")
{
	this->setDamage(30);
	this->setEnergy(100);
	this->setHitpoint(100);
	std::cout << "[FRAGTRAP] A FRAGTRAP was created.\n";
}
FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "[FRAGTRAP] A copy of FragTrap " << this->getName() << " was just created.\n";
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->setDamage(30);
	this->setEnergy(100);
	this->setHitpoint(100);
	std::cout << "[FRAGTRAP] A FragTrap " << name << " is created.\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FRAGTRAP] Rest in peace, FragTrap.\n";
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		std::cout << "[FRAGTRAP] A FragTrap copied " << this->getName() << ".\n";
	}
	return (*this);
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " offers a highfive!\n";
}
