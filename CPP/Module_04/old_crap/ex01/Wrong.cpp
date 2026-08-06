/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:25:28 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:58:25 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong.hpp"

WrongAnimal::WrongAnimal(): _type("")
{
	std::cout << "WrongAnimal was created\n";
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
	std::cout << "WrongAnimal of type '" << this->_type << "' was seen.\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) : WrongAnimal(copy._type) 
{
	std::cout << "An identical wronganimal appeared.\n";
};

WrongAnimal::~WrongAnimal()
{
	std::cout << "Good bye, " << (this->_type.empty() ? "WrongAnimal" : this->_type) << "\n";
}

void	WrongAnimal::operator=(WrongAnimal const &copy)
{
	this->_type = copy._type;
	std::cout << "This wronganimal was groomed indentically to the other one.";
}

void WrongAnimal::makeSound()
{
	std::cout << "A strange sound is heared\n";
}
// -----------------------------------
WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
	std::cout << "A WrongDog appeared..\n";
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog disappeared..\n";
}

WrongDog::WrongDog(WrongDog const &copy) : WrongAnimal(copy._type)
{
	std::cout << "A identically wrongdog appeared..\n";
}

void	WrongDog::operator=(WrongDog const &copy)
{
	this->_type = copy._type; // even tho its the same
	std::cout << "This wrongdog was groomed indentically to the other one.";
}

void	WrongDog::makeSound()
{
	std::cout << "**WrongDog barks**";
}
// ---------------------------------------------------
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "A WrongCat appeared..\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat disappeared..\n";
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy._type)
{
	std::cout << "A identically wrongcat appeared..\n";
}

void	WrongCat::operator=(WrongCat const &copy)
{
	this->_type = copy._type; // even tho its the same
	std::cout << "This wrongcat was groomed indentically to the other one.";
}
void	WrongCat::makeSound()
{
	std::cout << "**WrongCat meows**";
}