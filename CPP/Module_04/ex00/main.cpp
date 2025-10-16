/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:49:25 by zali              #+#    #+#             */
/*   Updated: 2025/10/16 03:03:08 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int	main(void)
{
	// Testing makeSound
	std::cout << "-- Without Virtual Override --\n\n";
	WrongAnimal *wan;
	wan = new WrongDog();
	std::cout << "-----------------------\n";
	wan->makeSound();
	std::cout << "-----------------------\n";
	delete wan;
	wan = new WrongCat();
	std::cout << "----------------------\n";
	wan->makeSound();
	std::cout << "----------------------\n";
	delete wan;

	std::cout << "\n\n\n";
	std::cout << "-- With Virtual Override --\n\n";
	Animal *an;
	an = new Dog();
	std::cout << "----------------------\n";
	an->makeSound();
	std::cout << "----------------------\n";
	delete an;
	an = new Cat();
	std::cout << "----------------------\n";
	an->makeSound();
	std::cout << "----------------------\n";
	delete an;
	
	// Note we make it on heap and not on stack - Object Slicing - EXPLAIN
	return (0);
}