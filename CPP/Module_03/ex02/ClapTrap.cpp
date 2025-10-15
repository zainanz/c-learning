/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:38:50 by zali              #+#    #+#             */
/*   Updated: 2025/10/13 20:45:39 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors

ClapTrap::ClapTrap(void) : _name("unnamed"), _hitpoint(10), _energy(10), _damage(10)
{
	std::cout << "[CLAPTRAP] A ClapTrap is created.\n";
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hitpoint(10), _energy(10), _damage(10) 
{
	std::cout << "[CLAPTRAP] ClapTrap " << name << " is created.\n";
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _name(copy._name), _hitpoint(copy._hitpoint), _energy(copy._energy), _damage(copy._damage)
{
	std::cout << "[CLAPTRAP] A copy of ClapTrap " << this->getName() << " was created.\n";
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "[CLAPTRAP] Good bye, " << this->_name << ".\n";
}

// Copy Function
ClapTrap	&ClapTrap::operator=(ClapTrap const &copy) {
	this->_damage = copy._damage;
	this->_hitpoint = copy._hitpoint;
	this->_energy = copy._energy;
	this->_name = copy._name;
	std::cout << "[CLAPTRAP] A Claptrap copied " << copy._name << ".\n";
	return (*this);
}

// ClapTrap Functions
void		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has been damaged, lost " << amount << " hitpoints.\n";
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << this->_name << " attacked '" << target << "', causing " << this->_damage << " points of damage!\n";
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has been repaired, gained " << amount << " hitpoints.\n";
}

// Getters
std::string	&ClapTrap::getName(void)
{
	return (this->_name);
}

int			ClapTrap::getDamage(void)
{
	return (this->_damage);
}

int			ClapTrap::getEnergy(void)
{
	return (this->_energy);
}

int			ClapTrap::getHitpoint(void)
{
	return (this->_hitpoint);
}

// Setters
void	ClapTrap::setName(std::string const &name)
{
	this->_name = name;
}

void	ClapTrap::setDamage(int n)
{
	this->_damage = n;
}

void	ClapTrap::setEnergy(int n)
{
	this->_energy = n;
}

void	ClapTrap::setHitpoint(int n)
{
	this->_hitpoint = n;
}