/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:10:31 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 06:08:09 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()	: Animal(){
	this->type = "Dog";
	std::cout << "Dog entered the scene. [Default Constructor]" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog was chased away. [Destructor]" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy){
	std::cout << "An identical dog entered. [Copy Constructor]" << std::endl;
	//*this = copy;
}

Dog&	Dog::operator=(const Dog& copy){
	if (this == &copy) return (*this);
	std::cout << "An indentical dog entered. [Assignment Operator]" << std::endl;
	this->type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "Dog: woof!" << std::endl;
}