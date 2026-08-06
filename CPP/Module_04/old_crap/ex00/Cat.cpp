/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:52:30 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:49:40 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "A Cat appeared..\n";
}

Cat::~Cat()
{
	std::cout << "Cat disappeared..\n";
}

Cat::Cat(Cat const &copy) : Animal(copy._type)
{
	std::cout << "A identically cat appeared..\n";
}

void	Cat::operator=(Cat const &copy)
{
	this->_type = copy._type; // even tho its the same
	std::cout << "This cat was groomed indentically to the other one.\n";
}
void	Cat::makeSound()
{
	std::cout << "**Cat meows**\n";
}