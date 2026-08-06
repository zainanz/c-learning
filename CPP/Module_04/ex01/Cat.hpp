/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:11:11 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 09:00:38 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat&				operator=(const Cat& copy);
		void				makeSound(void) const;
		void				setIdea(const std::string& idea, int index);
		void				addIdea(const std::string& idea);
		const std::string&	getIdea(int idx) const;
	private:
		Brain *brain_;

};