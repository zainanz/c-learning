/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:22:28 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 09:01:05 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()	: Animal(){
	this->type = "Cat";
	std::cout << "A random stray cat appread." << std::endl;
	this->brain_ = new Brain();
}

Cat::~Cat(){
	std::cout << "The stray cat ran away!" << std::endl;
	delete this->brain_;
}

Cat::Cat(const Cat& copy) : Animal(copy){
	std::cout << "Another identical stray cat appeared out of the bush! [Copy Constructor]" << std::endl;
	this->brain_ = new Brain();
	*this = copy;
}

Cat&	Cat::operator=(const Cat& copy){
	if (this == &copy) return (*this);
	std::cout << "Another identical stray cat appeared! [Assignment Operator]" << std::endl;
	*(this->brain_) = *(copy.brain_);
	this->type = copy.type;
	return (*this);
}
void	Cat::makeSound(void) const{
	std::cout << "Cat meows!" << std::endl;

}

void Cat::setIdea(const std::string& idea, int index){
	this->brain_->ideas[index] = idea;
}


void Cat::addIdea(const std::string& idea){
	this->brain_->addIdea(idea);
}

const std::string& Cat::getIdea(int idx) const{
	if (idx < 0 || idx >= MAX_IDEAS){
		std::cout << "Cat::getIdea -> INVALID IDX: can only be 0-99 | returning DEFAULT IDX 0" << std::endl;
		return this->brain_->ideas[0];
	}
	return this->brain_->ideas[idx];
}