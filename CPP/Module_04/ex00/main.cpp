/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:09:14 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 06:48:11 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

		std::cout << std::endl << std::endl;
		std::cout << "Wrong Animal Example:" << std::endl;
		const WrongAnimal* wronga = new WrongAnimal();
		const WrongAnimal* wrongc = new WrongCat();
		wronga->makeSound();
		wrongc->makeSound();
		((WrongCat*)(wrongc))->makeSound();
		delete wronga;
		delete wrongc;
	
	return 0;
}