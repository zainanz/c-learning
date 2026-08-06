/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:22:28 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 06:21:54 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()	: WrongAnimal(){
	this->type = "WrongCat";
	std::cout << "A random wrong stray cat appread." << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "The wrong stray cat ran away!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy){
	std::cout << "Another identical wrong stray cat appeared out of the bush! [Copy Constructor]" << std::endl;
	//*this = copy;
}

WrongCat&	WrongCat::operator=(const WrongCat& copy){
	if (this == &copy) return (*this);
	std::cout << "Another identical wrong stray cat appeared! [Assignment Operator]" << std::endl;
	this->type = copy.type;
	return (*this);
}
void	WrongCat::makeSound(void) const{
	std::cout << "WrongCat meows!" << std::endl;

}