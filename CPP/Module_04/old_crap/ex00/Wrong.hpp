/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:23:11 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 02:44:37 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_HPP
# define WRONG_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal();
		~WrongAnimal();
		void operator=(WrongAnimal const &copy);
		void makeSound();
	protected:
		std::string _type;
};

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		~WrongDog();
		WrongDog(WrongDog const &copy);
		void	operator=(WrongDog const &copy);
		void	makeSound(void);
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat const &copy);
		void	operator=(WrongCat const &copy);
		void	makeSound(void);
};
#endif