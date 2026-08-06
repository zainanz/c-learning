/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 04:06:28 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 05:00:05 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "A ScavTrap is created." << std::endl;
	this->setName("ScavTrap_unnamed");
	this->setHitpoint(100);
	this->setEnergy(50);
	this->setDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	//*this = other; Not Needed because ClapTrap does the same thing
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
	std::cout << "ScavTrap " << name << " is created." << std::endl;
	this->setHitpoint(100);
	this->setEnergy(50);
	this->setDamage(20);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap] Good bye, " << this->getName() << "." << std::endl;
}

// Operator
ScavTrap&	ScavTrap::operator=(const ScavTrap& other){
	std::cout << "ScavTrap Assignment Operator was used" << std::endl;
	if (this == &other) return (*this);
	this->setName(other.getName());
	this->setHitpoint(other.getHitpoint());
	this->setEnergy(other.getEnergy());
	this->setDamage(other.getDamage());
	return (*this);
}



void	ScavTrap::attack(std::string const &target)
{
	if (this->getEnergy() <= 0) {
		std::cout << "[X] ScavTrap " << this->getName() << " does not have enough energy to attack!" << std::endl;
		return ;
	}
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "[X] ScavTrap " << this->getName() << " attacked '" << target << "', causing " << this->getDamage() << " points of damage! [" << this->getEnergy() << " Energy Remaining]"  << std::endl;
	// Trigger ScavTrap's Take Damage
	return ;
}


void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " turned on guard gate mode." << std::endl;
}