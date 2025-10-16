/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:45:42 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:47:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("")
{
	std::cout << "An Animal was seen\n";
}

Animal::Animal(std::string const &type) : _type(type)
{
	std::cout << "Animal of type '" << this->_type << "' was seen.\n";
}

Animal::Animal(Animal const &copy) : Animal(copy._type) 
{
	std::cout << "An identical animal appeared.\n";
};

Animal::~Animal()
{
	std::cout << "Good bye, " << (this->_type.empty() ? "Animal" : this->_type) << "\n";
}

void	Animal::operator=(Animal const &copy)
{
	this->_type = copy._type;
	std::cout << "This animal was groomed indentically to the other one.\n";
}

void Animal::makeSound()
{
	std::cout << "A strange sound is heared\n";
}