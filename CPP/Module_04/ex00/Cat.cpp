/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:22:28 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 07:34:15 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()	: Animal(){
	this->type = "Cat";
	std::cout << "A random stray cat appread." << std::endl;
}

Cat::~Cat(){
	std::cout << "The stray cat ran away!" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy){
	std::cout << "Another identical stray cat appeared out of the bush! [Copy Constructor]" << std::endl;
	//*this = copy;
}

Cat&	Cat::operator=(const Cat& copy){
	if (this == &copy) return (*this);
	std::cout << "Another identical stray cat appeared! [Assignment Operator]" << std::endl;
	this->type = copy.type;
	return (*this);
}
void	Cat::makeSound(void) const{
	std::cout << "Cat meows!" << std::endl;

}