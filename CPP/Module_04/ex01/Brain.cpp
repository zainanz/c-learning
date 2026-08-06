/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 07:20:54 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 10:05:17 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	this->ideaIDX = 0;
}

Brain::~Brain(){
}

Brain::Brain(const Brain& copy){
	*this = copy;
}

void	Brain::addIdea(const std::string& idea){
	if (this->ideaIDX >= MAX_IDEAS - 1) this->ideaIDX = 0;
	this->ideas[this->ideaIDX] = idea;
	std::cout << "[Added Idea] '" << this->ideas[this->ideaIDX] << "' [idx: " << this->ideaIDX << "] " << std::endl;
	this->ideaIDX++;
	return ;
}

Brain&	Brain::operator=(const Brain& copy){
	if (this == &copy) return (*this);
	std::copy(copy.ideas, copy.ideas + MAX_IDEAS, this->ideas);
	this->ideaIDX = copy.ideaIDX;
	return (*this);
}
