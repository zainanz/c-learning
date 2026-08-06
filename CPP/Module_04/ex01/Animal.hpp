/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:09:31 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 09:09:03 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal {
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal&	operator=(const Animal& copy);
		const std::string&	getType(void) const;
		void				setType(const std::string& type);
		virtual void				makeSound(void) const;
	protected:
		std::string	type;
};