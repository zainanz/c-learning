/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:10:39 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 06:07:55 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <iostream>
class Dog: public Animal{
	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog&	operator=(const Dog& copy);
		void	makeSound(void) const;

};