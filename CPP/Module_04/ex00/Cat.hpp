/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:11:11 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 06:07:59 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Animal.hpp"
#include <iostream>
class Cat: public Animal{
	public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat&	operator=(const Cat& copy);
		void	makeSound(void) const;

};