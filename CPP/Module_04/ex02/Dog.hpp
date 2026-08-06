/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:10:39 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 09:00:58 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog&				operator=(const Dog& copy);
		void				makeSound(void) const;
		void				setIdea(const std::string& idea, int index);
		void				addIdea(const std::string& idea);
		const std::string&	getIdea(int idx) const;
	private:
		Brain*	brain_;

};