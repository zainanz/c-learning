/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 02:04:49 by zali              #+#    #+#             */
/*   Updated: 2026/08/03 06:15:14 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap(){
	std::cout << "FragTrap FragTrap_unnamed was created." << "[Default Constructor]" << std::endl;
	this->setName("FragTrap_unnamed");
	this->setHitpoint(100);
	this->setEnergy(100);
	this->setDamage(30);
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name){
	std::cout << "FragTrap " << name << " was created." << "[String/Name Constructor]" << std::endl;
	this->setHitpoint(100);
	this->setEnergy(100);
	this->setDamage(30);
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
	std::cout << "FragTrap " << this->getName() << " was cloned. [Copy Constructor]" << std::endl;
	// *this = other;
	//  -> Not Needed since ClapTrap's constructor already copies everything once
}

FragTrap&	FragTrap::operator=(const FragTrap& other){
	std::cout << "FragTrap " << this->getName() << " was cloned. [Assignemnt Operator]" << std::endl;
	if (this == &other) return (*this);
	this->setHitpoint(other.getHitpoint());
	this->setEnergy(other.getEnergy());
	this->setDamage(other.getDamage());
	return (*this);
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap " << this->getName() << " was destroyed. [Destructor]" << std::endl;
}
void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->getName() << " wants to highfive!" << std::endl;

}