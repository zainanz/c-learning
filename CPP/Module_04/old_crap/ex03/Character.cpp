/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:00:46 by zali              #+#    #+#             */
/*   Updated: 2025/10/19 15:30:50 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
Character::Character(std::string const &name): _name(name)
{
	for (int i = 0; i < MAX_MAT; i++)
		Mats[i] = NULL;
};

Character::~Character()
{
	for (int i = 0; i < MAX_MAT ; i++)
	{
		if (this->Mats[i] != NULL)
			delete this->Mats[i];
	}
}

Character::Character(Character const &copy) : _name(copy.getName())
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		if (this->Mats[i])
			delete this->Mats[i];
		if (copy.Mats[i] != NULL)
			this->Mats[i] = copy.Mats[i]->clone();
		else
			this->Mats[i] = NULL;
	}
}

std::string const	&Character::getName() const
{
	return (this->_name);	
}

void				Character::equip(AMateria *m)
{
	for (int i = 0; i < MAX_MAT ; i++)
	{
		if (this->Mats[i] == NULL)
		{
			this->Mats[i] = m;
			break ;
		}
	}
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_MAT)
	{
		std::cout << this->_name << " threw away the" << this->Mats[idx]->getType() << ".\n";
		this->Mats[idx] = NULL;	
	}
	else
		std::cout << this->_name << " just tried to unequip something that doenst exist.\n";
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0  && idx < MAX_MAT)
	{
		if (this->Mats[idx])
			this->Mats[idx]->use(target);
	}
	else
		std::cout << this->_name << " didn't find anyhting in the backpack (index out of range)..\n";
}