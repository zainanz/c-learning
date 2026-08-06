/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:52:30 by zali              #+#    #+#             */
/*   Updated: 2025/10/18 22:07:47 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "A Dog appeared..\n";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog disappeared..\n";
	delete this->_brain;
}

Dog::Dog(Dog const &copy) : Animal(copy._type), _brain(new Brain(*copy._brain))
{
	std::cout << "A identically dog appeared..\n";
}

void	Dog::operator=(Dog const &copy)
{
	this->_type = copy._type; // even tho its the same
	*this->_brain = *copy._brain;
	std::cout << "This dog was groomed indentically to the other one.\n";
}

Brain	&Dog::getBrain()
{
	return (*(this->_brain));
}

void	Dog::makeSound()
{
	std::cout << "**Dog barks**\n";
}