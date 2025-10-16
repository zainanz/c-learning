/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:12:32 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:48:14 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat const &copy);
		void	operator=(Cat const &copy);
		void	makeSound() override;
};

#endif