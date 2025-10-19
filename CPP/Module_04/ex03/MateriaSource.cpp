/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:46:40 by zali              #+#    #+#             */
/*   Updated: 2025/10/19 15:24:42 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
	for (int i = 0; i < MAX_LEARN ; i++)
		this->learned[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_LEARN ; i++)
		if (this->learned[i])
			delete this->learned[i];
}

MateriaSource::MateriaSource(MateriaSource const &copy) 
{
	for (int i = 0; i < MAX_LEARN; i++)	
	{
		if (this->learned[i])
			delete this->learned[i];
		if (copy.learned[i])
			this->learned[i] = copy.learned[i]->clone();
		else
			this->learned[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &copy)
{
	for (int i = 0; i < MAX_LEARN; i++)	
	{
		if (this->learned[i])
			delete this->learned[i];
		if (copy.learned[i])
			this->learned[i] = copy.learned[i]->clone();
		else
			this->learned[i] = NULL;
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < MAX_LEARN; i++)
	{
		if (!this->learned[i])
		{
			std::cout << "Successfully studied the prototype of " << materia->getType() << ".\n";
			this->learned[i] = materia->clone();
			return ;
		}
	}
	std::cout << "Failed to understand the prototype.\n";
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_LEARN; i++)
	{
		if (!this->learned[i])
			continue ;
		if (this->learned[i]->getType() == type)
			return (this->learned[i]->clone());
	}
	return (NULL);
}