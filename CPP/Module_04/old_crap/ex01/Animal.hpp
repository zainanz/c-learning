/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:11:08 by zali              #+#    #+#             */
/*   Updated: 2025/10/18 21:15:26 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		Animal(std::string const &type);
		Animal(Animal const &copy);
		Animal();
		virtual ~Animal();
		Animal		&operator=(Animal const &copy);
		virtual Brain 		&getBrain(void) = 0;
		virtual void 		makeSound() = 0;
		std::string			&getType();
	protected:
		std::string _type;
};
#endif