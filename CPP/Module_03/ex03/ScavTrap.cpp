/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:03:39 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 00:39:59 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(void) : ClapTrap("unnamed")
{
	this->setDamage(20);
	this->setEnergy(50);
	this->setHitpoint(100);
	std::cout << "[SCAVTRAP] A ScavTrap was created.\n";
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->setDamage(20);
	this->setEnergy(50);
	this->setHitpoint(100);
	std::cout << "[SCAVTRAP] ScavTrap " << name << " is created.\n";
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "[SCAVTRAP] A copy of ScavTrap " << this->getName() << " was just created.\n";
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)

{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		std::cout << "[SCAVTRAP] A SCAVTRAP copied " << this->getName() << ".\n";
	}
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "[SCAVTRAP] Rest in peace, ScavTrap.\n";
}

// Class function
void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << this->getName() << " *blasted* '" << target << "', causing " << this->getDamage() << " points of damage!\n";
	
}
void		ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " has turned on gate keeper mode.\n";
}
