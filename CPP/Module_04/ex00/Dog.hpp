/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:12:32 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:47:44 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog const &copy);
		void	operator=(Dog const &copy);
		void	makeSound() override;
};

#endif