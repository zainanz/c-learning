/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:10:31 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 09:01:02 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()	: Animal(){
	this->type = "Dog";
	std::cout << "Dog entered the scene. [Default Constructor]" << std::endl;
	this->brain_ = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog was chased away. [Destructor]" << std::endl;
	delete this->brain_;
}

Dog::Dog(const Dog& copy): Animal(copy){
	std::cout << "An identical dog entered. [Copy Constructor]" << std::endl;
	this->brain_ = new Brain();
	*this = copy;
}

Dog&	Dog::operator=(const Dog& copy){
	if (this == &copy) return (*this);
	std::cout << "An indentical dog entered. [Assignment Operator]" << std::endl;

	*(this->brain_) = *(copy.brain_);
	this->type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "Dog: woof!" << std::endl;
}

void Dog::setIdea(const std::string& idea, int index){
	this->brain_->ideas[index] = idea;
}

void Dog::addIdea(const std::string& idea){
	this->brain_->addIdea(idea);
}

const std::string& Dog::getIdea(int idx) const{
	if (idx < 0 || idx >= MAX_IDEAS){
		std::cout << "Dog::getIdea -> INVALID IDX: can only be 0-99 | returning DEFAULT IDX 0" << std::endl;
		return this->brain_->ideas[0];
	}
	return this->brain_->ideas[idx];
}