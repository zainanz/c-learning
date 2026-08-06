/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:52:30 by zali              #+#    #+#             */
/*   Updated: 2025/10/18 22:10:24 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "A Cat appeared..\n";
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat disappeared..\n";
	delete this->_brain;
}

Cat::Cat(Cat const &copy) : Animal(copy._type), _brain(new Brain(*copy._brain))
{
	std::cout << "A identically cat appeared..\n";
}

void	Cat::operator=(Cat const &copy)
{
	this->_type = copy._type; // even tho its the same
	*this->_brain = *copy._brain;
	std::cout << "This cat was groomed indentically to the other one.\n";
}

Brain	&Cat::getBrain()
{
	return (*(this->_brain));
}

void	Cat::makeSound()
{
	std::cout << "**Cat meows**\n";
}