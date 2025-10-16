/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:11:08 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:48:00 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
class Animal
{
	public:
		Animal(std::string const &type);
		Animal(Animal const &copy);
		Animal();
		~Animal();
		void operator=(Animal const &copy);
		virtual void makeSound();
	protected:
		std::string _type;
};
#endif