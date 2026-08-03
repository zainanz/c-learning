/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:38:50 by zali              #+#    #+#             */
/*   Updated: 2025/10/13 20:44:25 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors

ClapTrap::ClapTrap(void) : name_("unnamed"), hitpoint_(10), energy_(10), damage_(10)
{
	std::cout << "A ClapTrap is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

ClapTrap::ClapTrap(const std::string& name) : name_(name), hitpoint_(10), energy_(10), damage_(10) 
{
	std::cout << "ClapTrap " << name << " is created." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Good bye, " << this->name_ << "." << std::endl;
}

// Operator
ClapTrap&	ClapTrap::operator=(const ClapTrap& other){
	std::cout << "Assignment Operator was used" << std::endl;
	if (this == &other) return (*this);
	this->name_ = other.name_;
	this->hitpoint_ = other.hitpoint_;
	this->energy_ = other.energy_;
	this->damage_ = other.damage_;
	return (*this);
}


// Public Member Functions
void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitpoint_ <= 0){
		std::cout << "Dead ClapTrap " << this->name_ << " took " << amount << " damage. [DEAD]" << std::endl;
		return ;
	}
	if (this->hitpoint_ - static_cast<int>(amount) <= 0){
		std::cout << "ClapTrap " << this->name_ << " took " << amount << " damage and died! [RIP]" << std::endl;
		this->hitpoint_ = 0;
	}
	else{
		this->hitpoint_ -= amount;
		std::cout << "ClapTrap " << this->name_ << " took " << amount << " damage. [" << this->hitpoint_ << "HP]" << std::endl;
	}
	return ;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->energy_ <= 0) {
		std::cout << "ClapTrap " << this->name_ << " does not have enough energy to attack!" << std::endl;
		return ;
	}
	this->energy_--;
	std::cout << "ClapTrap " << this->name_ << " attacked '" << target << "', causing " << this->damage_ << " points of damage! [" << this->energy_ << " Energy Remaining]"  << std::endl;
	// Trigger ClapTrap's Take Damage
	return ;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_ <= 0) {
		std::cout << "ClapTrap " << this->name_ << " does not have enough energy to repair!" << std::endl;
		return ;
	}
	this->energy_--;
	this->hitpoint_ += amount;
	std::cout << "ClapTrap " << this->name_ << " has been repaired, gained " << amount << " hitpoints. [" << this->hitpoint_ << " HP + " << this->energy_ << " Energy Remaining]" << std::endl;
}

// Getters
const std::string	&ClapTrap::getName(void) const
{
	return (this->name_);
}

int			ClapTrap::getDamage(void)
{
	return (this->damage_);
}

int			ClapTrap::getEnergy(void)
{
	return (this->energy_);
}

int			ClapTrap::getHitpoint(void)
{
	return (this->hitpoint_);
}

// Setters
void	ClapTrap::setName(std::string const &name)
{
	this->name_ = name;
}

void	ClapTrap::setDamage(int n)
{
	this->damage_ = n;
}

void	ClapTrap::setEnergy(int n)
{
	this->energy_ = n;
}

void	ClapTrap::setHitpoint(int n)
{
	this->hitpoint_ = n;
}