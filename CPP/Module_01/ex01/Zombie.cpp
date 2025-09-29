/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:26:50 by zali              #+#    #+#             */
/*   Updated: 2025/09/28 18:10:31 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "A zombie spawned in the Jura-Tempest Federation..\n";
};

Zombie::~Zombie(void)
{
	std::cout << "Temple Knights and Crusaders executed " << this->_name << ".\n";
}

void	Zombie::nameZombie(std::string name)
{
	this->_name = name;
	std::cout << "Rimuru named a zombie to '" << name << "'; evolved into a bigZ.\n";
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}