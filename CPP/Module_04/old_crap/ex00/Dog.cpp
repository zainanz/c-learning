/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:52:30 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:49:34 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "A Dog appeared..\n";
}

Dog::~Dog()
{
	std::cout << "Dog disappeared..\n";
}

Dog::Dog(Dog const &copy) : Animal(copy._type)
{
	std::cout << "A identically dog appeared..\n";
}

void	Dog::operator=(Dog const &copy)
{
	this->_type = copy._type; // even tho its the same
	std::cout << "This dog was groomed indentically to the other one.\n";
}

void	Dog::makeSound()
{
	std::cout << "**Dog barks**\n";
}