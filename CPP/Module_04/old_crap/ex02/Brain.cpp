/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:09:15 by zali              #+#    #+#             */
/*   Updated: 2025/10/18 22:04:22 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){};

Brain::Brain(Brain const &copy)
{
	std::cout << "An identical Brain was created.\n";
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
}

Brain	&Brain::operator=(Brain const &copy)
{
	std::cout << "Brain just copied ideas.\n";
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
	return (*this);
}
Brain::~Brain()
{
	std::cout << "Brain is dead.\n"; 
}
	
void	Brain::setIdea(std::string const &idea, int const index)
{
	this->_ideas[index] = idea;
}

std::string &Brain::getIdea(int const index)
{
	return (this->_ideas[index]);
}