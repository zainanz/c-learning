/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:31:12 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 00:37:15 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name")
{
	std::cout << "[DIAMONGTRAP] A DiamondTrap was created.\n";
	this->setDamage(FragTrap::getDamage());
	this->setEnergy(ScavTrap::getEnergy());
	this->setHitpoint(FragTrap::getHitpoint());
}

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->setDamage(FragTrap::getDamage());
	this->setEnergy(ScavTrap::getEnergy());
	this->setHitpoint(FragTrap::getHitpoint());
	std::cout << "[DIAMONGTRAP] DiamondTrap " << this->_name << " was created.\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "[DIAMONGTRAP] A copy of DiamondTrap " << this->_name << " was created.\n";
	this->_name = copy._name;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		this->_name = copy._name;
		std::cout << "DiamondTrap " << copy._name << " was copied.\n";
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DIAMONGTRAP] Diamond Trap " << this->_name << " is no longer with us.\n";
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hi, I am " << this->_name << " aka " << this->getName() << "\n";
}