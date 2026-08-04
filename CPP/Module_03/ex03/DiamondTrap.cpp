/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 03:03:57 by zali              #+#    #+#             */
/*   Updated: 2026/08/04 03:38:26 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(){ 
	std::cout << "DiamondTrap DiamondTrap_unnamed_clap_name was created! [Default Constructor]" << std::endl;
	ClapTrap::setName("DiamondTrap_unnamed_clap_name");
	this->name_ = "DiamondTrap_unnamed";
	this->setHitpoint(100);
	this->setEnergy(50);
	this->setDamage(30);
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), FragTrap(name), ScavTrap(name){ 	
	std::cout << "DiamondTrap " << name << " was cloned! [Name/String Constructor]" << std::endl;
	ClapTrap::setName(name + "_clap_name");
	this->name_ = name;
	this->setHitpoint(100);
	this->setEnergy(50);
	this->setDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{ 
	std::cout << "DiamondTrap " << other.getName() << " was cloned! [Copy Constructor]" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << this->name_ << " was destroyed!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other){
	std::cout << "DiamondTrap " << other.name_ << " was cloned! [Assignment Opereator]" << std::endl;
	if (this == &other) return (*this);
	this->ClapTrap::setName(other.ClapTrap::getName());
	this->name_ = other.name_;
	this->setHitpoint(other.getHitpoint());
	this->setEnergy(other.getEnergy());
	this->setDamage(other.getDamage());
	return (*this);
}
void	DiamondTrap::whoAmI(void){
	std::cout << "My Details {name_: " << this->name_ << ", ClapTrapName: " << ClapTrap::getName() << ", damage_: " << this->getDamage() << ", hitpoint_: " << this->getHitpoint() << ", energy_: " << this->getEnergy() << "}" << std::endl;
	return ;
}

void	DiamondTrap::setName(const std::string& name) {
	this->name_ = name;
}

const std::string&	DiamondTrap::getName(void) const{
	return (this->name_);
}